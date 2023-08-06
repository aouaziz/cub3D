/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 22:53:28 by mmalih            #+#    #+#             */
/*   Updated: 2023/08/06 04:13:55 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_mlx(t_cube *cube)
{
	cube->mlx = mlx_init();
	if (!cube->mlx)
		clean_exit(cube, 1);
	cube->win = mlx_new_window(cube->mlx, SCREEN_WIDTH, SCREEN_HEIGHT,
			"FPS_3D");
	if (!cube->win)
		clean_exit(cube, 1);
	return ;
}

void	start_map(t_cube *cube)
{
	if (cube->map[0] == NULL)
		ft_print_error("Invalid Map\n");
	cube = check_map_lines(cube);
	init_mlx(cube);
	init_player_direction(cube);
	init_textures(cube);
	render_images(cube);
	listen_for_input(cube);
	mlx_loop_hook(cube->mlx, engine, cube);
	mlx_loop(cube->mlx);
}
