/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 09:56:46 by aouaziz           #+#    #+#             */
/*   Updated: 2023/07/31 11:10:39 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	start_Map(t_cube *cube)
{
	if (cube->map[0] == NULL)
		ft_print_error("Invalid Map\n");
	cube = check_Map_Lines(cube);
	print_cube3d(cube);
    //ft_put_mini_map(cube);
	// init_textures(cube);
	// render_images(cube);
	// listen_for_input(cube);
	// mlx_loop_hook(cube->mlx, engine, cube);
	// mlx_loop(cube->mlx);
}