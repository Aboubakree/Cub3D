/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 06:37:03 by lissam            #+#    #+#             */
/*   Updated: 2024/10/10 12:02:34 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cub3d(char **av)
{
	t_data	my_data;

	check_map_file(av[1]);
	init_my_data(&my_data);
	check_map_file_content(av[1], &my_data);
	ft_draw(&my_data);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		print_error("Invalide number of params !!\n");
	cub3d(av);
}
