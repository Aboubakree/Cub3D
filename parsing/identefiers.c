/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identefiers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:09:28 by lissam            #+#    #+#             */
/*   Updated: 2024/11/11 11:20:09 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_textures(t_data *mydata)
{
	int	i;
	int	fd;

	i = 0;
	fd = 0;
	while (i < 6)
	{
		if (is_texture(mydata->idf_data[i][0]))
		{
			fd = open(mydata->idf_data[i][1], O_RDONLY);
			if (fd < 0)
			{
				ft_putstr_fd(mydata->idf_data[i][1]);
				ft_putstr_fd(" invalide texture file \n");
				get_next_line(-500);
				free_idf_data(mydata);
				exit(1);
			}
		}
		i++;
	}
}

void	checks(t_data *mydata)
{
	free_identefiers(mydata);
	check_identifiers_types(mydata);
	check_identifiers_dup(mydata);
	check_textures(mydata);
	check_colors(mydata);
}
