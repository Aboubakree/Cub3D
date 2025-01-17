/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identefiers_utils1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:09:18 by lissam            #+#    #+#             */
/*   Updated: 2024/10/10 13:09:03 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	count_rgb_numbers(t_data *mydata, char **str, int *j)
{
	if (*j != 3)
	{
		get_next_line(-500);
		ft_putstr_fd("color number error !!\n");
		*j = 0;
		while (str[*j])
		{
			free(str[*j]);
			*j = *j + 1;
		}
		free(str);
		free_idf_data(mydata);
		exit(1);
	}
}

void	check_colors(t_data *mydata)
{
	char	**str;

	int (i), (j);
	i = 0;
	j = 0;
	str = NULL;
	while (i < 6)
	{
		if (is_color(mydata->idf_data[i][0]))
		{
			j = 0;
			check_end_color(mydata, mydata->idf_data[i][1]);
			str = ft_split(mydata->idf_data[i][1], " 	,\n");
			chack_is_valid_color(mydata, str, &j);
			count_rgb_numbers(mydata, str, &j);
			j = 0;
			while (str[j])
			{
				free(str[j]);
				j++;
			}
			free(str);
		}
		i++;
	}
}

int	compare_identifiers(char *str)
{
	if (ft_strcmp(str, "NO") && ft_strcmp(str, "SO") && ft_strcmp(str, "WE")
		&& ft_strcmp(str, "EA") && ft_strcmp(str, "C") && ft_strcmp(str, "F"))
		return (1);
	return (0);
}

int	is_texture(char *str)
{
	if (!ft_strcmp(str, "NO") || !ft_strcmp(str, "SO") || !ft_strcmp(str, "WE")
		|| !ft_strcmp(str, "EA"))
		return (1);
	return (0);
}

void	check_textures_extension(t_data *mydata)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (is_texture(mydata->idf_data[i][0]))
		{
			if (ft_strcmp(mydata->idf_data[i][1]
				+ (ft_strlen(mydata->idf_data[i][1]) - 4), ".xpm") != 0)
			{
				ft_putstr_fd("invalide texture file extension\n");
				free_idf_data(mydata);
				exit(1);
			}
		}
		i++;
	}
}
