/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 11:12:00 by aouaziz           #+#    #+#             */
/*   Updated: 2023/08/03 19:49:59 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	print_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		printf("%s\n", str[i]);
		i++;
	}
	printf("\n");
}
void	print_textur(t_texinfo *textur)
{
	
	printf("Type: north , File: %s\n", textur->north);
	printf("Type: south , File: %s\n", textur->south);
	printf("Type: west , File: %s\n", textur->west);
	printf("Type: east , File: %s\n", textur->east);
	printf("Type: floor , File: %lu\n", textur->hex_floor);
	printf("Type: ceiling , File: %lu\n", textur->hex_ceiling);
}

void	print_cube3d(t_cube *cube)
{
	printf(YELLOW "\n---- MAP\n" RESET);
	printf("Map height: %d\n", cube->mapinfo.height);
	printf("Map width: %d\n", cube->mapinfo.width);
	print_str(cube->map);
	printf(YELLOW "\n---- TEXTURES & COLORS\n" RESET);
	printf("Color ceiling: #%lx\n", cube->texinfo.hex_ceiling);
	printf("Color floor: #%lx\n", cube->texinfo.hex_floor);
	printf("Texture north: %s\n", cube->texinfo.north);
	printf("Texture south: %s\n", cube->texinfo.south);
	printf("Texture east: %s\n", cube->texinfo.east);
	printf("Texture west: %s\n", cube->texinfo.west);
	printf(YELLOW "\n---- PLAYER\n" RESET);
	printf("Player pos: ");
	printf("x = %f, y = %f\n", cube->player.pos_x, cube->player.pos_y);
	printf("Player direction: %c ", cube->player.dir);
	printf("(x = %f, y = %f)\n", cube->player.dir_x, cube->player.dir_y);
	printf("/n");
}