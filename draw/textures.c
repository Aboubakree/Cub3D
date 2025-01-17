/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:41:54 by lissam            #+#    #+#             */
/*   Updated: 2024/10/10 11:41:55 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	texture_allocat(t_texture **texture)
{
	*texture = malloc(sizeof(t_texture));
	if (*texture == NULL)
		(perror("texture malloc"), exit(1));
	(*texture)->no_texture = malloc(sizeof(t_image_data));
	if ((*texture)->no_texture == NULL)
		(perror("texture malloc"), exit(1));
	(*texture)->so_texture = malloc(sizeof(t_image_data));
	if ((*texture)->so_texture == NULL)
		(perror("texture malloc"), exit(1));
	(*texture)->we_texture = malloc(sizeof(t_image_data));
	if ((*texture)->we_texture == NULL)
		(perror("texture malloc"), exit(1));
	(*texture)->ea_texture = malloc(sizeof(t_image_data));
	if ((*texture)->ea_texture == NULL)
		(perror("texture malloc"), exit(1));
}

void	get_texture_img(t_data *data, t_texture *texture)
{
	texture->no_texture->img = mlx_xpm_file_to_image(data->mlx, data->no_file,
			&texture->no_texture->tex_width, &texture->no_texture->tex_heigth);
	if (texture->no_texture->img == NULL)
		(perror("xpm_to_img"), exit(1));
	texture->so_texture->img = mlx_xpm_file_to_image(data->mlx, data->so_file,
			&texture->so_texture->tex_width, &texture->so_texture->tex_heigth);
	if (texture->so_texture->img == NULL)
		(perror("xpm_to_img"), exit(1));
	texture->we_texture->img = mlx_xpm_file_to_image(data->mlx, data->we_file,
			&texture->we_texture->tex_width, &texture->we_texture->tex_heigth);
	if (texture->we_texture->img == NULL)
		(perror("xpm_to_img"), exit(1));
	texture->ea_texture->img = mlx_xpm_file_to_image(data->mlx, data->ea_file,
			&texture->ea_texture->tex_width, &texture->ea_texture->tex_heigth);
	if (texture->ea_texture->img == NULL)
		(perror("xpm_to_img"), exit(1));
}

void	get_texture_data_addr(t_texture *texture)
{
	texture->no_texture->addr = mlx_get_data_addr(texture->no_texture->img,
			&texture->no_texture->bits_per_pixel,
			&texture->no_texture->line_length, &texture->no_texture->endian);
	texture->so_texture->addr = mlx_get_data_addr(texture->so_texture->img,
			&texture->so_texture->bits_per_pixel,
			&texture->so_texture->line_length, &texture->so_texture->endian);
	texture->we_texture->addr = mlx_get_data_addr(texture->we_texture->img,
			&texture->we_texture->bits_per_pixel,
			&texture->we_texture->line_length, &texture->we_texture->endian);
	texture->ea_texture->addr = mlx_get_data_addr(texture->ea_texture->img,
			&texture->ea_texture->bits_per_pixel,
			&texture->ea_texture->line_length, &texture->ea_texture->endian);
}

void	texture_init(t_data *data)
{
	t_texture	*texture;

	texture = NULL;
	texture_allocat(&texture);
	get_texture_img(data, texture);
	get_texture_data_addr(texture);
	data->texture = texture;
}
