/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrid <akrid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 09:33:51 by lissam            #+#    #+#             */
/*   Updated: 2024/10/23 18:43:16 by akrid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_player(t_player *player)
{
	player->i = 0;
	player->j = 0;
	player->rotationangle = M_PI / 2;
	player->movespeed = 3;
	player->rotationspeed = 2 * (M_PI / 180);
	player->to_turn = 0;
	player->to_walk = 0;
}

void	init_vars(t_raycast *vars)
{
	vars->h_hit = 0;
	vars->v_hit = 0;
	vars->x = 0;
	vars->y = 0;
	vars->h_wall_x = 0;
	vars->h_wall_y = 0;
	vars->v_wall_x = 0;
	vars->v_wall_y = 0;
	vars->h_step_x = 0;
	vars->h_step_y = 0;
	vars->v_step_x = 0;
	vars->v_step_y = 0;
	vars->distance_h = 0;
	vars->distance_v = 0;
	vars->first_x = 0;
	vars->first_y = 0;
	vars->next_x = 0;
	vars->next_y = 0;
	vars->rayangle = 0;
}

void	horizontal_data_init(double x, double y, t_raycast *vars)
{
	vars->first_y = floor(y / SQUAR_SIZE) * SQUAR_SIZE;
	if (check_down(vars->rayangle))
		vars->first_y += SQUAR_SIZE;
	else
		vars->first_y -= 0.0001;
	vars->first_x = x + ((vars->first_y - y) / tan(vars->rayangle));
	vars->h_step_y = SQUAR_SIZE;
	if (!check_down(vars->rayangle))
		vars->h_step_y *= -1;
	vars->h_step_x = SQUAR_SIZE / tan(vars->rayangle);
	if ((!check_right(vars->rayangle) && vars->h_step_x > 0)
		|| (check_right(vars->rayangle) && vars->h_step_x < 0))
		vars->h_step_x *= -1;
	vars->next_x = vars->first_x;
	vars->next_y = vars->first_y;
}

void	vertical_data_init(double x, double y, t_raycast *vars)
{
	vars->first_x = floor(x / SQUAR_SIZE) * SQUAR_SIZE;
	if (check_right(vars->rayangle))
		vars->first_x += SQUAR_SIZE;
	else
		vars->first_x -= 0.0001;
	vars->first_y = y + ((vars->first_x - x) * tan(vars->rayangle));
	vars->v_step_x = SQUAR_SIZE;
	if (!check_right(vars->rayangle))
		vars->v_step_x *= -1;
	vars->v_step_y = SQUAR_SIZE * tan(vars->rayangle);
	if ((!check_down(vars->rayangle) && vars->v_step_y > 0)
		|| (check_down(vars->rayangle) && vars->v_step_y < 0))
		vars->v_step_y *= -1;
	vars->next_x = vars->first_x;
	vars->next_y = vars->first_y;
}

void	calculate_distance(double x, double y, t_raycast *vars)
{
	if (vars->h_hit)
		vars->distance_h = distance(x, y, vars->h_wall_x, vars->h_wall_y);
	else
		vars->distance_h = INT_MAX;
	if (vars->v_hit)
		vars->distance_v = distance(x, y, vars->v_wall_x, vars->v_wall_y);
	else
		vars->distance_v = INT_MAX;
}
