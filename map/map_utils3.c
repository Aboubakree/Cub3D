/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 09:59:19 by lissam            #+#    #+#             */
/*   Updated: 2024/11/11 15:16:22 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_arround(t_data *mydata, int i, int j)
{
	check_line_up_down(mydata, i, j + 1);
	if (j == 0 || mydata->tmp_map[i][j + 1] == '\n' || mydata->tmp_map[i][j
		+ 1] == '\0')
	{
		free_idf_data(mydata);
		free_tmp_map(mydata);
		print_error("Invalide map\n");
	}
	check_character_up_down(mydata, i, j);
	if (mydata->tmp_map[i][j + 1] == ' ' || mydata->tmp_map[i][j + 1] == '\t')
	{
		free_idf_data(mydata);
		free_tmp_map(mydata);
		print_error("Invalide map\n");
	}
	if (mydata->tmp_map[i][j - 1] == ' ' || mydata->tmp_map[i][j - 1] == '\t')
	{
		free_idf_data(mydata);
		free_tmp_map(mydata);
		print_error("Invalide map\n");
	}
}

void	check_first_line(t_data *mydata, int i)
{
	int	j;

	j = 0;
	while (mydata->tmp_map[i][j])
	{
		if (mydata->tmp_map[i][j] != '1' && mydata->tmp_map[i][j] != '\n'
			&& mydata->tmp_map[i][j] != '\t' && mydata->tmp_map[i][j] != ' ')
		{
			free_idf_data(mydata);
			free_tmp_map(mydata);
			print_error("Invalide map \n");
		}
		j++;
	}
}

void	check_map_validating(t_data *mydata)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (mydata->tmp_map[mydata->tmp_map_h - 1][j])
	{
		chack_last_line(mydata, &j);
		j++;
	}
	check_first_line(mydata, i);
	while (i < (mydata->tmp_map_h))
	{
		j = 0;
		while (mydata->tmp_map[i][j] == ' ' || mydata->tmp_map[i][j] == '\t')
			j++;
		if (mydata->tmp_map[i][j] == '\n' || mydata->tmp_map[i][j] == '\0')
			i++;
		else
		{
			check_walls(mydata, i);
			i++;
		}
	}
}

int	get_map_with(t_data *mydata)
{
	int	i;
	int	width;
	int	tmp_width;

	i = 0;
	tmp_width = 0;
	width = ft_strlen3(mydata->map[0]);
	while (i < mydata->map_h && mydata->map[i])
	{
		tmp_width = ft_strlen3(mydata->map[i]);
		if (tmp_width > width)
			width = tmp_width;
		i++;
	}
	return (width);
}

void	fill_the_map(t_data *mydata, int s, int e)
{
	int (i), (map_size);
	i = 0;
	map_size = (e - s + 1);
	mydata->map = malloc((e - s + 1) * sizeof(char *));
	if (!mydata->map)
	{
		free_idf_data(mydata);
		free_tmp_map(mydata);
		print_error("Malloc error\n");
	}
	while (i < map_size)
	{
		mydata->map[i] = ft_strdup(mydata->tmp_map[s]);
		i++;
		s++;
	}
	mydata->map_h = i;
	mydata->map_w = get_map_with(mydata);
	make_map_square(mydata, mydata->map_w, mydata->map_h);
}
