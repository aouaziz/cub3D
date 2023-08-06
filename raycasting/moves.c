/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 22:53:46 by mmalih            #+#    #+#             */
/*   Updated: 2023/08/06 03:34:35 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	move_forward(t_cube *cube)
{
	double	new_x;
	double	new_y;

	new_x = cube->player.pos_x + cube->player.dir_x * SPEED;
	new_y = cube->player.pos_y + cube->player.dir_y * SPEED;
	return (ft_move(cube, new_x, new_y));
}

static int	move_backward(t_cube *cube)
{
	double	new_x;
	double	new_y;

	new_x = cube->player.pos_x - cube->player.dir_x * SPEED;
	new_y = cube->player.pos_y - cube->player.dir_y * SPEED;
	return (ft_move(cube, new_x, new_y));
}

static int	move_left(t_cube *cube)
{
	double	new_x;
	double	new_y;

	new_x = cube->player.pos_x + cube->player.dir_y * SPEED;
	new_y = cube->player.pos_y - cube->player.dir_x * SPEED;
	return (ft_move(cube, new_x, new_y));
}

static int	move_right(t_cube *cube)
{
	double	new_x;
	double	new_y;

	new_x = cube->player.pos_x - cube->player.dir_y * SPEED;
	new_y = cube->player.pos_y + cube->player.dir_x * SPEED;
	return (ft_move(cube, new_x, new_y));
}

int	move_player(t_cube *cube)
{
	int	moved;

	moved = 0;
	if (cube->player.move_y == 1)
		moved += move_forward(cube);
	if (cube->player.move_y == -1)
		moved += move_backward(cube);
	if (cube->player.move_x == 1)
		moved += move_left(cube);
	if (cube->player.move_x == -1)
		moved += move_right(cube);
	if (cube->player.rotate != 0)
		moved += rotate(cube, cube->player.rotate);
	return (moved);
}
