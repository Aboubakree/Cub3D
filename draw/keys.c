/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:42:02 by lissam            #+#    #+#             */
/*   Updated: 2024/10/10 11:42:28 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	key_press(int key, t_data *data)
{
	if (key == KEY_A)
		data->player->to_walk = 1;
	else if (key == KEY_D)
		data->player->to_walk = 2;
	else if (key == KEY_W)
		data->player->to_walk = 3;
	else if (key == KEY_S)
		data->player->to_walk = 4;
	else if (key == KEY_LEFT)
		data->player->to_turn = 1;
	else if (key == KEY_RIGHT)
		data->player->to_turn = 2;
	else if (key == 65307)
		close_w(data);
	return (0);
}

int	key_release(int key, t_data *data)
{
	if (key == KEY_A || key == KEY_D || key == KEY_S || key == KEY_W)
		data->player->to_walk = 0;
	else if (key == KEY_RIGHT || key == KEY_LEFT)
		data->player->to_turn = 0;
	return (0);
}

int	render(t_data *mydata)
{
	move_keys(0, mydata);
	move_rows(0, mydata);
	draw(mydata->img, mydata, mydata->player);
	return (0);
}
