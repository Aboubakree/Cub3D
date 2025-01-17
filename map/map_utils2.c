/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 09:59:12 by lissam            #+#    #+#             */
/*   Updated: 2024/10/10 10:00:06 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_characterrs(t_data *mydata)
{
	int (i), (j);
	i = 0;
	while (i < mydata->tmp_map_h && mydata->tmp_map[i])
	{
		j = 0;
		while (mydata->tmp_map[i][j] == ' ' || (mydata->tmp_map[i][j] >= 9
				&& mydata->tmp_map[i][j] <= 13))
			j++;
		if (mydata->tmp_map[i][j] == '\0' || mydata->tmp_map[i][j] == '\n')
			i++;
		else
		{
			while (mydata->tmp_map[i][j])
			{
				if (have_forbidden_char(mydata->tmp_map[i][j]))
				{
					free_idf_data(mydata);
					free_tmp_map(mydata);
					print_error("Map contains forbidden character\n");
				}
				j++;
			}
			i++;
		}
	}
}

void	map_error_separating(int countnewlines, int countlines, t_data *mydata)
{
	if (countnewlines == 0 || countlines == 0)
	{
		free_idf_data(mydata);
		free_tmp_map(mydata);
		print_error("Map Error!\n");
	}
}

void	check_separating(t_data *mydata)
{
	int	i;
	int	j;
	int	countnewlines;
	int	countlines;

	i = 0;
	j = 0;
	countnewlines = 0;
	countlines = 0;
	while (i < mydata->tmp_map_h && mydata->tmp_map[i])
	{
		j = 0;
		while (mydata->tmp_map[i][j] == ' ' || mydata->tmp_map[i][j] == '\t')
			j++;
		if (mydata->tmp_map[i][j] == '\n')
			countnewlines++;
		else if (mydata->tmp_map[i][j] != '\0' && mydata->tmp_map[i][j] != '\n')
		{
			countlines++;
			break ;
		}
		i++;
	}
	map_error_separating(countnewlines, countlines, mydata);
}

int	ft_strlen3(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

void	check_line_up_down(t_data *mydata, int i, int j)
{
	int	before_len;
	int	after_len;

	before_len = ft_strlen3(mydata->tmp_map[i - 1]);
	after_len = ft_strlen3(mydata->tmp_map[i + 1]);
	if (j > before_len || j > after_len)
	{
		free_idf_data(mydata);
		free_tmp_map(mydata);
		print_error("Invalide map\n");
	}
}
