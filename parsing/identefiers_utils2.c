/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identefiers_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:09:23 by lissam            #+#    #+#             */
/*   Updated: 2024/10/10 13:08:41 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_identifiers_dup(t_data *mydata)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	while (i < 6)
	{
		count = 0;
		j = 0;
		while (j < 6)
		{
			if (!ft_strcmp(mydata->idf_data[i][0], mydata->idf_data[j][0]))
				count++;
			j++;
		}
		if (count > 1)
		{
			ft_putstr_fd("duplicated identifier !!\n");
			get_next_line(-500);
			free_idf_data(mydata);
			exit(1);
		}
		i++;
	}
}

int	is_color(char *str)
{
	if (!ft_strcmp(str, "C") || !ft_strcmp(str, "F"))
		return (1);
	return (0);
}

int	is_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	check_identifiers_types(t_data *mydata)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (compare_identifiers(mydata->idf_data[i][0]))
		{
			ft_putstr_fd(mydata->idf_data[i][0]);
			ft_putstr_fd(" is not a valide identifier \n");
			get_next_line(-500);
			free_idf_data(mydata);
			exit(1);
		}
		i++;
	}
}

void	count_identifier_attr(t_data *mydata)
{
	int	i;
	int	j;

	i = 0;
	while (i < 6)
	{
		j = 0;
		while (mydata->idf_data[i][j])
			j++;
		if (j != 2)
		{
			free_identefiers(mydata);
			free_idf_data(mydata);
			get_next_line(-500);
			print_error("identifiers error\n");
		}
		i++;
	}
}
