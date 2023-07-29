/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:55:46 by aouaziz           #+#    #+#             */
/*   Updated: 2023/07/29 11:42:02 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"



int	main(int ac, char *av[])
{
 	t_cube	cube;

	init_cube(&cube);
	if (ac != 2)
		ft_print_error("Incorrect Number of Arguments\n");
	check_File_And_Read_it(av[1],&cube);
}
