/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:55:46 by aouaziz           #+#    #+#             */
/*   Updated: 2023/07/31 13:47:05 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	get_Map_width(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	return (i);
}

int	main(int ac, char *av[])
{
	t_cube	cube;

	init_cube(&cube);
	if (ac != 2)
		ft_print_error("Incorrect Number of Arguments\n");
	check_File_And_Read_it(av[1], &cube);
}
t_cube	*get_Map_width_And_Height(t_cube *cube)
{
	int	x_len;
	int	height;

	cube->mapinfo.height = 0;
	cube->mapinfo.width = 0;
	height = 0;
	while (cube->map[height])
	{
		x_len = get_Map_width(cube->map[cube->mapinfo.height]);
		if (x_len > cube->mapinfo.width)
			cube->mapinfo.width = x_len;
		cube->mapinfo.height++;
		height++;
	}
	while (cube->map[cube->mapinfo.height - 1][0] == '\n')
		cube->mapinfo.height--;
	return (cube);
}
