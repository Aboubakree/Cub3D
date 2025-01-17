/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_checkers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:41:26 by akrid             #+#    #+#             */
/*   Updated: 2024/11/11 13:15:43 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	normalizeray(double rayangle)
{
	rayangle = fmod(rayangle, 2 * M_PI);
	if (rayangle < 0)
		rayangle += 2 * M_PI;
	return (rayangle);
}

int	check_right(double rayangle)
{
	if (rayangle < (M_PI / 2) || rayangle > ((3 * M_PI) / 2))
		return (1);
	return (0);
}

int	check_down(double rayangle)
{
	if (rayangle > 0 && rayangle < M_PI)
		return (1);
	return (0);
}

int	wall_hit(t_data *mydata, double x, double y)
{
	int	i;
	int	j;

	i = floor(y / SQUAR_SIZE);
	j = floor(x / SQUAR_SIZE);
	if (i < 0 || i >= mydata->map_h || j < 0 || j >= mydata->map_w)
		return (0);
	return (mydata->map[i][j] == '1');
}

double	distance(double x1, double y1, double x2, double y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}
