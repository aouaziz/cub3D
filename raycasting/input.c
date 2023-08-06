/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 22:53:22 by mmalih            #+#    #+#             */
/*   Updated: 2023/08/06 03:34:23 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_quit(t_cube *cube)
{
	clean_exit(cube, 0);
	return (0);
}

int	key_press(int key, t_cube *cube)
{
	if (key == ESC_KEY)
		ft_quit(cube);
	if (key == LEFT_ARROW)
		cube->player.rotate -= 1;
	if (key == RIGHT_ARROW)
		cube->player.rotate += 1;
	if (key == W_KEY)
		cube->player.move_y = 1;
	if (key == A_KEY)
		cube->player.move_x = -1;
	if (key == S_KEY)
		cube->player.move_y = -1;
	if (key == D_KEY)
		cube->player.move_x = 1;
	return (0);
}

int	key_release(int key, t_cube *cube)
{
	if (key == ESC_KEY)
		ft_quit(cube);
	if (key == W_KEY && cube->player.move_y == 1)
		cube->player.move_y = 0;
	if (key == S_KEY && cube->player.move_y == -1)
		cube->player.move_y = 0;
	if (key == A_KEY && cube->player.move_x == -1)
		cube->player.move_x += 1;
	if (key == D_KEY && cube->player.move_x == 1)
		cube->player.move_x -= 1;
	if (key == LEFT_ARROW && cube->player.rotate <= 1)
		cube->player.rotate = 0;
	if (key == RIGHT_ARROW && cube->player.rotate >= -1)
		cube->player.rotate = 0;
	return (0);
}

void	listen_for_input(t_cube *cube)
{
	mlx_hook(cube->win, 33, 0L, ft_quit, cube);
	mlx_hook(cube->win, 2, (1L << 0), key_press, cube);
	mlx_hook(cube->win, 3, (1L << 1), key_release, cube);
}

int	engine(t_cube *cube)
{
	cube->player.has_moved += move_player(cube);
	if (cube->player.has_moved == 0)
		return (0);
	render_images(cube);
	return (0);
}
