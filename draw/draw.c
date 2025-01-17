/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 09:33:40 by lissam            #+#    #+#             */
/*   Updated: 2024/10/22 20:49:41 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	my_mlx_pixel_put(t_image_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x <= WIN_W && y <= WIN_H)
	{
		dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel
					/ 8));
		*(unsigned int *)dst = color;
	}
}

void	draw(t_image_data *img, t_data *mydata, t_player *player)
{
	castrays(mydata, player);
	mlx_put_image_to_window(mydata->mlx, mydata->win, img->img, 0, 0);
}

int	wall_check(t_data *mydata, double x, double y)
{
	int	index_x;
	int	index_y;

	if (x < 0 || x > (mydata->map_w * SQUAR_SIZE) || y < 0 || y > (mydata->map_h
			* SQUAR_SIZE))
		return (0);
	index_x = floor(x / SQUAR_SIZE);
	index_y = floor(y / SQUAR_SIZE);
	if (mydata->map[index_y][index_x] != '0')
		return (0);
	index_x = floor((x + 1) / SQUAR_SIZE);
	if (mydata->map[index_y][index_x] != '0')
		return (0);
	index_x = floor((x - 1) / SQUAR_SIZE);
	if (mydata->map[index_y][index_x] != '0')
		return (0);
	index_x = floor(x / SQUAR_SIZE);
	index_y = floor((y + 1) / SQUAR_SIZE);
	if (mydata->map[index_y][index_x] != '0')
		return (0);
	index_y = floor((y - 1) / SQUAR_SIZE);
	if (mydata->map[index_y][index_x] != '0')
		return (0);
	else
		return (1);
}

void	move_rows(int keycode, t_data *mydata)
{
	(void)keycode;
	if (mydata->player->to_turn == 1)
	{
		mydata->player->rotationangle -= mydata->player->rotationspeed;
	}
	else if (mydata->player->to_turn == 2)
	{
		mydata->player->rotationangle += mydata->player->rotationspeed;
	}
}

void	ft_draw(t_data *mydata)
{
	t_image_data	img;
	t_player		player;

	init_player(&player);
	get_player(&player, mydata);
	mydata->mlx = mlx_init();
	mydata->win = mlx_new_window(mydata->mlx, WIN_W, WIN_H, "cub3d");
	img.img = mlx_new_image(mydata->mlx, WIN_W, WIN_H);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	mydata->player = &player;
	mydata->img = &img;
	texture_init(mydata);
	mlx_hook(mydata->win, 2, 1L << 0, key_press, mydata);
	mlx_hook(mydata->win, 3, 1L << 1, key_release, mydata);
	mlx_hook(mydata->win, 17, 1L << 0, close_w, mydata);
	mlx_loop_hook(mydata->mlx, render, mydata);
	mlx_loop(mydata->mlx);
}
