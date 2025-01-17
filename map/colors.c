/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 09:59:01 by lissam            #+#    #+#             */
/*   Updated: 2024/10/10 10:01:53 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_rgb_to_int(int red, int green, int blue)
{
	return ((red << 16) | (green << 8) | blue);
}

void	get_f_hex(t_data *mydata)
{
	char	**str;

	int (i), (j);
	i = 0;
	j = 0;
	while (i < 6 && mydata->idf_data[i])
	{
		if (!ft_strcmp(mydata->idf_data[i][0], "F"))
		{
			str = ft_split(mydata->idf_data[i][1], " 	,\n");
			mydata->f_color = ft_rgb_to_int(ft_atoi(str[0]), ft_atoi(str[1]),
					ft_atoi(str[2]));
			while (str[j])
				free(str[j++]);
			free(str);
		}
		i++;
	}
}

void	get_c_hex(t_data *mydata)
{
	char	**str;

	int (i), (j);
	i = 0;
	j = 0;
	while (i < 6 && mydata->idf_data[i])
	{
		if (!ft_strcmp(mydata->idf_data[i][0], "C"))
		{
			str = ft_split(mydata->idf_data[i][1], " 	,\n");
			mydata->c_color = ft_rgb_to_int(ft_atoi(str[0]), ft_atoi(str[1]),
					ft_atoi(str[2]));
			while (str[j])
				free(str[j++]);
			free(str);
		}
		i++;
	}
}

void	get_file_colors(t_data *mydata)
{
	int	i;

	i = 0;
	while (i < 6 && mydata->idf_data[i])
	{
		if (!ft_strcmp(mydata->idf_data[i][0], "SO"))
			mydata->so_file = ft_strdup(mydata->idf_data[i][1]);
		else if (!ft_strcmp(mydata->idf_data[i][0], "NO"))
			mydata->no_file = ft_strdup(mydata->idf_data[i][1]);
		else if (!ft_strcmp(mydata->idf_data[i][0], "WE"))
			mydata->we_file = ft_strdup(mydata->idf_data[i][1]);
		else if (!ft_strcmp(mydata->idf_data[i][0], "EA"))
			mydata->ea_file = ft_strdup(mydata->idf_data[i][1]);
		if (!ft_strcmp(mydata->idf_data[i][0], "F"))
			get_f_hex(mydata);
		if (!ft_strcmp(mydata->idf_data[i][0], "C"))
			get_c_hex(mydata);
		i++;
	}
}
