/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 09:59:07 by lissam            #+#    #+#             */
/*   Updated: 2024/10/10 09:59:08 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	skip_identifiers(int fd)
{
	char	*str;
	int		i;
	int		j;

	j = 0;
	str = get_next_line(fd);
	while (str && j < 6)
	{
		i = 0;
		while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
			i++;
		if (str[i] != '\0' && str[i] != '\n')
			j++;
		free(str);
		str = NULL;
		if (j == 6)
			break ;
		str = get_next_line(fd);
	}
}

void	fill(int fd, t_data *mydata)
{
	char	*str;
	int		i;

	str = get_next_line(fd);
	i = 0;
	while (str && i < mydata->tmp_map_h)
	{
		mydata->tmp_map[i] = ft_strdup(str);
		i++;
		free(str);
		str = get_next_line(fd);
	}
}

void	fill_tmp_map(t_data *mydata, char *map_file)
{
	int	fd;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		free_idf_data(mydata);
		free(mydata->tmp_map);
		print_error("map file error !!\n");
	}
	skip_identifiers(fd);
	fill(fd, mydata);
}

int	have_forbidden_char(char c)
{
	if (c != '0' && c != '1' && c != 'W' && c != 'E' && c != 'N' && c != 'S'
		&& c != ' ' && c != '\t' && c != '\n')
		return (1);
	return (0);
}

void	check_position_char(t_data *mydata)
{
	int	i;
	int	j;
	int	found;

	i = 0;
	j = 0;
	found = 0;
	while (i < mydata->tmp_map_h && mydata->tmp_map[i])
	{
		j = 0;
		while (mydata->tmp_map[i][j])
		{
			if (mydata->tmp_map[i][j] == 'N' || mydata->tmp_map[i][j] == 'S'
				|| mydata->tmp_map[i][j] == 'E' || mydata->tmp_map[i][j] == 'W')
				found++;
			j++;
		}
		i++;
	}
	if (found != 1)
	{
		free_idf_data(mydata);
		free_tmp_map(mydata);
		print_error("Map characters error\n");
	}
}
