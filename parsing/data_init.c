/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:09:04 by lissam            #+#    #+#             */
/*   Updated: 2024/10/24 09:21:13 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_my_data(t_data *mydata)
{
	int	i;

	i = 0;
	while (i < 6)
		mydata->identifier[i++] = NULL;
	mydata->idf_data = NULL;
	mydata->fov = 60 * (M_PI / 180);
}

void	init_tmp_map(t_data *mydata, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		mydata->tmp_map[j] = NULL;
		j++;
	}
}
