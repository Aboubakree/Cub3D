/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 09:59:23 by lissam            #+#    #+#             */
/*   Updated: 2024/10/10 12:02:17 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_the_map(t_data *mydata)
{
	int (s), (e), (j);
	s = 0;
	j = 0;
	e = mydata->tmp_map_h - 1;
	while (mydata->tmp_map[s])
	{
		j = 0;
		while (mydata->tmp_map[s][j] == ' ' || mydata->tmp_map[s][j] == '\t')
			j++;
		if (mydata->tmp_map[s][j] == '\n' || mydata->tmp_map[s][j] == '\0')
			s++;
		else
			break ;
	}
	while (mydata->tmp_map[e])
	{
		j = 0;
		while (mydata->tmp_map[e][j] == ' ' || mydata->tmp_map[e][j] == '\t')
			j++;
		if (mydata->tmp_map[e][j] == '\n' || mydata->tmp_map[e][j] == '\0')
			e--;
		else
			break ;
	}
	fill_the_map(mydata, s, e);
}

void	map_parsing(t_data *mydata)
{
	check_separating(mydata);
	check_characterrs(mydata);
	check_position_char(mydata);
	check_map_validating(mydata);
	get_the_map(mydata);
	get_file_colors(mydata);
	free_tmp_map(mydata);
	free_idf_data(mydata);
}

void	the_map(int fd, t_data *mydata, char *map_file)
{
	char	*str;
	int		i;

	i = 0;
	str = get_next_line(fd);
	while (str)
	{
		free(str);
		i++;
		str = get_next_line(fd);
	}
	mydata->tmp_map_h = i;
	free(str);
	close(fd);
	mydata->tmp_map = malloc(sizeof(char *) * i);
	if (!mydata->tmp_map)
	{
		free_idf_data(mydata);
		print_error("Malloc error\n");
	}
	init_tmp_map(mydata, i);
	fill_tmp_map(mydata, map_file);
	map_parsing(mydata);
}
