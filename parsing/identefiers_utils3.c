/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identefiers_utils3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:49:57 by lissam            #+#    #+#             */
/*   Updated: 2024/10/10 13:09:32 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	identifiers_validation(t_data *mydata)
{
	int (i);
	i = 0;
	mydata->idf_data = malloc(6 * sizeof(char **));
	if (!mydata->idf_data)
	{
		free_identefiers(mydata);
		print_error("Malloc error !!");
	}
	while (i < 6)
	{
		mydata->idf_data[i] = ft_split(mydata->identifier[i], "  \n");
		i++;
	}
	count_identifier_attr(mydata);
	checks(mydata);
}

void	check_identefiers(t_data *my_data)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (my_data->identifier[i] == NULL)
		{
			free_identefiers(my_data);
			print_error("Missed identifier !!\n");
		}
		i++;
	}
	identifiers_validation(my_data);
}

void	check_end_color(t_data *mydata, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (str[i - 1] == ',')
	{
		ft_putstr_fd("color error !!\n");
		get_next_line(-500);
		free_idf_data(mydata);
		exit(1);
	}
}

void	chack_is_valid_color(t_data *mydata, char **str, int *j)
{
	while (str[*j])
	{
		if (ft_strlen2(str[*j]) > 3 || !is_number(str[*j])
			|| (ft_atoi(str[*j]) < 0 || ft_atoi(str[*j]) > 255))
		{
			ft_putstr_fd("color number error !!\n");
			*j = 0;
			while (str[*j])
			{
				free(str[*j]);
				*j = *j + 1;
			}
			free(str);
			get_next_line(-500);
			free_idf_data(mydata);
			exit(1);
		}
		*j = *j + 1;
	}
}
