/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 11:12:00 by aouaziz           #+#    #+#             */
/*   Updated: 2023/08/03 19:37:31 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"


void	print_str_bonus(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		printf("%s\n", str[i]);
		i++;
	}
}
void	print_textur_bonus(t_texinfo *textur)
{
	printf("Type: north , File: %s\n", textur->north);
	printf("Type: south , File: %s\n", textur->south);
	printf("Type: west , File: %s\n", textur->west);
	printf("Type: east , File: %s\n", textur->east);
	printf("Type: floor , File: %lu\n", textur->hex_floor);
	printf("Type: ceiling , File: %lu\n", textur->hex_ceiling);
}

void	print_cube3d_bonus(t_cube *cube)
{
	printf("Player: %c\n", cube->player.dir);
	printf("X: %d\n", cube->player.move_x);
	printf("Y: %d\n", cube->player.move_y);
	printf("Map Length: %d\n", cube->mapinfo.width);
	printf("Map Height: %d\n", cube->mapinfo.height);
	printf("Map:\n");
	print_str_bonus(cube->map);
	printf("Textur:\n");
	print_textur_bonus(&cube->texinfo);
}
