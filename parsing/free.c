/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:09:11 by lissam            #+#    #+#             */
/*   Updated: 2024/10/10 10:02:02 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_identefiers(t_data *my_data)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		free(my_data->identifier[i]);
		my_data->identifier[i] = NULL;
		i++;
	}
}

void	free_idf_data(t_data *mydata)
{
	int	i;
	int	j;

	i = 0;
	while (i < 6)
	{
		j = 0;
		while (mydata->idf_data[i][j])
		{
			free(mydata->idf_data[i][j]);
			mydata->idf_data[i][j] = NULL;
			j++;
		}
		free(mydata->idf_data[i]);
		mydata->idf_data[i] = NULL;
		i++;
	}
	free(mydata->idf_data);
}

void	free_tmp_map(t_data *mydata)
{
	int	i;

	i = 0;
	while (i < mydata->tmp_map_h && mydata->tmp_map[i])
	{
		free(mydata->tmp_map[i]);
		mydata->tmp_map[i] = NULL;
		i++;
	}
	free(mydata->tmp_map);
}

void	free_map(t_data *mydata)
{
	int	i;

	i = 0;
	while (i < mydata->map_h)
	{
		free(mydata->map[i]);
		i++;
	}
	free(mydata->map);
}

void	free_used_data(t_data *mydata)
{
	free(mydata->so_file);
	free(mydata->no_file);
	free(mydata->we_file);
	free(mydata->ea_file);
	free_map(mydata);
}
