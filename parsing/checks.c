/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:08:55 by lissam            #+#    #+#             */
/*   Updated: 2024/11/11 11:27:18 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_map_file(char *map_file)
{
	int	map;

	map = open(map_file, O_RDONLY);
	if (map < 0)
	{
		print_error("Invalide map file !!\n");
	}
	if (ft_strcmp(map_file + (ft_strlen(map_file) - 4), ".cub") != 0)
	{
		close(map);
		print_error("Invalide file extension !!\n");
	}
	close(map);
}

void	file_is_open(int fd)
{
	if (fd < 0)
	{
		print_error("map file error !!\n");
	}
}

void	check_map_file_content(char *map_file, t_data *mydata)
{
	char	*str;

	int (fd), (i), (j);
	fd = open(map_file, O_RDONLY);
	file_is_open(fd);
	str = get_next_line(fd);
	i = 0;
	j = 0;
	while (str && j < 6)
	{
		while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
			i++;
		if (str[i] != '\0' && str[i] != '\n')
			mydata->identifier[j++] = ft_strdup(str + i);
		free(str);
		str = NULL;
		if (j == 6)
			break ;
		str = get_next_line(fd);
		i = 0;
	}
	free(str);
	check_identefiers(mydata);
	the_map(fd, mydata, map_file);
}

void	check_walls(t_data *mydata, int i)
{
	int	line_len;
	int	j;

	line_len = ft_strlen3(mydata->tmp_map[i]);
	j = 0;
	while (mydata->tmp_map[i][j] == ' ' || mydata->tmp_map[i][j] == '\t')
		j++;
	if ((mydata->tmp_map[i][j] != '\n' && mydata->tmp_map[i][j] != '\0')
		&& (mydata->tmp_map[i][j] == '0' || mydata->tmp_map[i][line_len
			- 1] == '0'))
	{
		free_idf_data(mydata);
		free_tmp_map(mydata);
		print_error("Invalide map\n");
	}
	while (j < line_len && mydata->tmp_map[i][j])
	{
		if (mydata->tmp_map[i][j] == '0' || mydata->tmp_map[i][j] == 'S'
			|| mydata->tmp_map[i][j] == 'E' || mydata->tmp_map[i][j] == 'N'
			|| mydata->tmp_map[i][j] == 'W')
			check_arround(mydata, i, j);
		j++;
	}
}

void	chack_last_line(t_data *mydata, int *j)
{
	if (mydata->tmp_map[mydata->tmp_map_h - 1][*j] != '1'
		&& mydata->tmp_map[mydata->tmp_map_h - 1][*j] != '\n'
		&& mydata->tmp_map[mydata->tmp_map_h - 1][*j] != '\t'
		&& mydata->tmp_map[mydata->tmp_map_h - 1][*j] != ' ')
	{
		free_idf_data(mydata);
		free_tmp_map(mydata);
		print_error("Invalide map \n");
	}
}
