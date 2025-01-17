/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 09:55:40 by lissam            #+#    #+#             */
/*   Updated: 2024/10/09 10:03:31 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	change_rotationangle(t_player *player, char p_char)
{
	if (p_char == 'S')
		player->rotationangle = M_PI / 2;
	else if (p_char == 'E')
		player->rotationangle = 0;
	else if (p_char == 'W')
		player->rotationangle = M_PI;
	else if (p_char == 'N')
		player->rotationangle = (3 * M_PI) / 2;
}

void	get_player(t_player *player, t_data *mydata)
{
	int	i;
	int	j;

	i = 0;
	while (i < mydata->map_h)
	{
		j = 0;
		while (mydata->map[i][j] != '\n' && mydata->map[i][j] != '\0')
		{
			if (mydata->map[i][j] == 'S' || mydata->map[i][j] == 'E'
				|| mydata->map[i][j] == 'W' || mydata->map[i][j] == 'N')
			{
				change_rotationangle(player, mydata->map[i][j]);
				player->i = (i * SQUAR_SIZE) + (SQUAR_SIZE / 2);
				player->j = (j * SQUAR_SIZE) + (SQUAR_SIZE / 2);
				mydata->map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
}

int	close_w(t_data *mydata)
{
	mlx_destroy_image(mydata->mlx, mydata->texture->no_texture->img);
	mlx_destroy_image(mydata->mlx, mydata->texture->ea_texture->img);
	mlx_destroy_image(mydata->mlx, mydata->texture->we_texture->img);
	mlx_destroy_image(mydata->mlx, mydata->texture->so_texture->img);
	free(mydata->texture->so_texture);
	free(mydata->texture->no_texture);
	free(mydata->texture->ea_texture);
	free(mydata->texture->we_texture);
	free(mydata->texture);
	mlx_destroy_image(mydata->mlx, mydata->img->img);
	mlx_destroy_window(mydata->mlx, mydata->win);
	mlx_destroy_display(mydata->mlx);
	free(mydata->mlx);
	free_used_data(mydata);
	exit(0);
}
