/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:53:53 by lissam            #+#    #+#             */
/*   Updated: 2024/11/11 10:54:27 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_character_up_down(t_data *mydata, int i, int j)
{
	if (mydata->tmp_map[i - 1][j] == ' ' || mydata->tmp_map[i - 1][j] == '\t')
	{
		free_idf_data(mydata);
		free_tmp_map(mydata);
		print_error("Invalide map\n");
	}
	if (mydata->tmp_map[i + 1][j] == ' ' || mydata->tmp_map[i + 1][j] == '\t')
	{
		free_idf_data(mydata);
		free_tmp_map(mydata);
		print_error("Invalide map\n");
	}
}
