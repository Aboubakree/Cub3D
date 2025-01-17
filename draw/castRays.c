/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   castRays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 09:32:32 by lissam            #+#    #+#             */
/*   Updated: 2024/10/24 09:24:09 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_horiz_inter(t_data *mydata, double x, double y, t_raycast *vars)
{
	horizontal_data_init(x, y, vars);
	while (vars->next_x >= 0 && vars->next_x <= mydata->map_w * SQUAR_SIZE
		&& vars->next_y >= 0 && vars->next_y <= mydata->map_h * SQUAR_SIZE)
	{
		if (wall_hit(mydata, vars->next_x, vars->next_y))
		{
			vars->h_hit = true;
			vars->h_wall_x = vars->next_x;
			vars->h_wall_y = vars->next_y;
			break ;
		}
		vars->next_x += vars->h_step_x;
		vars->next_y += vars->h_step_y;
	}
}

void	get_vert_inter(t_data *mydata, double x, double y, t_raycast *vars)
{
	vertical_data_init(x, y, vars);
	while (vars->next_x >= 0 && vars->next_x <= mydata->map_w * SQUAR_SIZE
		&& vars->next_y >= 0 && vars->next_y <= mydata->map_h * SQUAR_SIZE)
	{
		if (wall_hit(mydata, vars->next_x, vars->next_y))
		{
			vars->v_hit = true;
			vars->v_wall_x = vars->next_x;
			vars->v_wall_y = vars->next_y;
			break ;
		}
		vars->next_x += vars->v_step_x;
		vars->next_y += vars->v_step_y;
	}
}

double	get_closer_inter(t_data *mydata, double x, double y, t_raycast *vars)
{
	calculate_distance(x, y, vars);
	if (vars->distance_h < vars->distance_v)
	{
		mydata->inter_is_vertical = 0;
		mydata->inter_x = vars->h_wall_x;
		mydata->inter_y = vars->h_wall_y;
		if (vars->h_wall_y > mydata->player->i)
			mydata->texture_side = 2;
		else
			mydata->texture_side = 3;
		return (vars->distance_h);
	}
	else
	{
		mydata->inter_is_vertical = 1;
		mydata->inter_x = vars->v_wall_x;
		mydata->inter_y = vars->v_wall_y;
		if (vars->v_wall_x > mydata->player->j)
			mydata->texture_side = 0;
		else
			mydata->texture_side = 1;
		return (vars->distance_v);
	}
}

double	intersections(t_data *mydata, double x, double y, double rayangle)
{
	t_raycast	vars;

	init_vars(&vars);
	vars.rayangle = rayangle;
	get_horiz_inter(mydata, x, y, &vars);
	get_vert_inter(mydata, x, y, &vars);
	return (get_closer_inter(mydata, x, y, &vars));
}

void	castrays(t_data *mydata, t_player *player)
{
	int		col;
	double	rayangle;
	double	angle_step;
	double	distance;

	angle_step = mydata->fov / WIN_W;
	rayangle = player->rotationangle - (mydata->fov / 2);
	col = 0;
	while (col < WIN_W)
	{
		rayangle = normalizeray(rayangle);
		distance = intersections(mydata, player->j, player->i, rayangle);
		draw3d(mydata, distance, rayangle, col);
		col++;
		rayangle += angle_step;
	}
}
