/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 09:54:44 by lissam            #+#    #+#             */
/*   Updated: 2024/11/11 13:34:53 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_pixel(t_image_data *texture, int x_offset, int y_offset)
{
	char	*dst;
	int		pexel;

	pexel = 0;
	if (x_offset >= 0 && y_offset >= 0 && x_offset <= texture->tex_width
		&& y_offset <= texture->tex_heigth)
	{
		dst = texture->addr + (y_offset * texture->line_length + x_offset
				* (texture->bits_per_pixel / 8));
		pexel = *(unsigned int *)dst;
	}
	return (pexel);
}

t_image_data	*get_texture(t_data *data)
{
	if (data->texture_side == 0)
		return (data->texture->ea_texture);
	if (data->texture_side == 1)
		return (data->texture->we_texture);
	if (data->texture_side == 2)
		return (data->texture->so_texture);
	return (data->texture->no_texture);
}

void	draw_walls(t_data *mydata, t_data_to_draw to_draw_vars,
		int texture_offset_x, int c_or_f_color)
{
	double	wall_check;

	int (texture_offset_y), (dist_from_top);
	to_draw_vars.realdistance = to_draw_vars.distance
		* cos(to_draw_vars.rayangle - mydata->player->rotationangle);
	to_draw_vars.distanceprojplane = (WIN_W / 2.0) * tan(mydata->fov / 2.0);
	to_draw_vars.wallheight = (SQUAR_SIZE / to_draw_vars.realdistance)
		* to_draw_vars.distanceprojplane;
	if (to_draw_vars.wall_up_down == 0)
		wall_check = WIN_H / 2 - to_draw_vars.start;
	else
		wall_check = to_draw_vars.start - WIN_H / 2;
	if (wall_check <= to_draw_vars.wallheight / 2)
	{
		dist_from_top = to_draw_vars.start + (to_draw_vars.wallheight / 2)
			- (WIN_H / 2);
		texture_offset_y = dist_from_top * ((get_texture(mydata))->tex_heigth
				/ to_draw_vars.wallheight);
		my_mlx_pixel_put(mydata->img, to_draw_vars.col, to_draw_vars.start,
			get_pixel((get_texture(mydata)), texture_offset_x,
				texture_offset_y));
	}
	else
		my_mlx_pixel_put(mydata->img, to_draw_vars.col, to_draw_vars.start,
			c_or_f_color);
}

void	to_draw_init(t_data_to_draw	*to_draw_vars
	, double distance, double rayangle, int col)
{
	to_draw_vars->distance = distance;
	to_draw_vars->col = col;
	to_draw_vars->rayangle = rayangle;
	to_draw_vars->start = WIN_H / 2.0;
}

void	draw3d(t_data *mydata, double distance, double rayangle, int col)
{
	t_data_to_draw	to_draw_vars;
	int				texture_offset_x;

	to_draw_init(&to_draw_vars, distance, rayangle, col);
	if (mydata->inter_is_vertical)
		texture_offset_x = (int)mydata->inter_y
			% (get_texture(mydata))->tex_heigth;
	else
		texture_offset_x = (int)mydata->inter_x
			% (get_texture(mydata))->tex_width;
	while (to_draw_vars.start >= 0)
	{
		to_draw_vars.wall_up_down = 0;
		draw_walls(mydata, to_draw_vars, texture_offset_x, mydata->c_color);
		to_draw_vars.start--;
	}
	to_draw_vars.start = WIN_H / 2.0;
	while (to_draw_vars.start < WIN_H)
	{
		to_draw_vars.wall_up_down = 1;
		draw_walls(mydata, to_draw_vars, texture_offset_x, mydata->f_color);
		to_draw_vars.start++;
	}
}
