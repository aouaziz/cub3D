/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 11:12:00 by aouaziz           #+#    #+#             */
/*   Updated: 2023/07/31 09:48:15 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"


void	print_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		printf("%s\n", str[i]);
		i++;
	}
}
void	print_textur(t_texinfo *textur)
{
	printf("Type: north , File: %s\n", textur->north);
	printf("Type: south , File: %s\n", textur->south);
	printf("Type: west , File: %s\n", textur->west);
	printf("Type: east , File: %s\n", textur->east);
	printf("Type: floor , File: %d\n", textur->floor);
	printf("Type: ceiling , File: %d\n", textur->ceiling);
}

void	print_cube3d(t_cube *cube)
{
	printf("Player: %c\n", cube->player.dir);
	printf("X: %d\n", cube->player.move_x);
	printf("Y: %d\n", cube->player.move_y);
	printf("Map Length: %d\n", cube->win_width);
	printf("Map Height: %d\n", cube->win_height);
	printf("Map:\n");
	print_str(cube->map);
	printf("Textur:\n");
	print_textur(&cube->texinfo);
}
