/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_it_square.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:19:34 by lissam            #+#    #+#             */
/*   Updated: 2024/11/11 13:32:41 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	is_valid_map_char(char c)
{
	return (c == '0' || c == '1' || c == 'S' || c == 'N' || c == 'E'
		|| c == 'W');
}

static char	*init_row(t_data *mydata, int w)
{
	int		j;
	char	*tmp;

	tmp = malloc((w + 1) * sizeof(char));
	if (!tmp)
	{
		free_idf_data(mydata);
		free_tmp_map(mydata);
		print_error("Malloc error\n");
	}
	j = 0;
	while (j < w)
		tmp[j++] = '1';
	tmp[w] = '\0';
	return (tmp);
}

static void	copy_row(char *tmp, char *map_row, int w)
{
	int	j;

	j = 0;
	while (j < w && map_row[j])
	{
		if (is_valid_map_char(map_row[j]))
			tmp[j] = map_row[j];
		j++;
	}
}

static void	update_row(t_data *mydata, int i, int w)
{
	char	*tmp;

	tmp = init_row(mydata, w);
	copy_row(tmp, mydata->map[i], w);
	free(mydata->map[i]);
	mydata->map[i] = tmp;
}

void	make_map_square(t_data *mydata, int w, int h)
{
	int	i;

	i = 0;
	while (i < h)
	{
		update_row(mydata, i, w);
		i++;
	}
	mydata->map_w = w;
	mydata->map_h = h;
}
