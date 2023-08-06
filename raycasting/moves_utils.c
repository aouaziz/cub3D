/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 22:53:41 by mmalih            #+#    #+#             */
/*   Updated: 2023/08/06 03:28:30 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	is_valid_pos_wall_collision(t_cube *cube, double x, double y)
{
	if (cube->map[(int)y][(int)x] == '0')
		return (true);
	return (false);
}

bool	is_valid_pos_in_map(t_cube *cube, double x, double y)
{
	if (x < 0.25 || x >= cube->mapinfo.width - 1.25)
		return (false);
	if (y < 0.25 || y >= cube->mapinfo.height - 0.25)
		return (false);
	return (true);
}

bool	is_valid_pos(t_cube *cube, double x, double y)
{
	if (is_valid_pos_in_map(cube, x, y) && is_valid_pos_wall_collision(cube, x,
			y))
		return (true);
	return (false);
}

int	ft_move(t_cube *cube, double new_x, double new_y)
{
	int	moved;

	moved = 0;
	if (is_valid_pos(cube, new_x, cube->player.pos_y))
	{
		cube->player.pos_x = new_x;
		moved = 1;
	}
	if (is_valid_pos(cube, cube->player.pos_x, new_y))
	{
		cube->player.pos_y = new_y;
		moved = 1;
	}
	return (moved);
}

int	rotate_left_right(t_cube *cube, double rotspeed)
{
	t_player	*p;
	double		tmp_x;

	p = &cube->player;
	tmp_x = p->dir_x;
	p->dir_x = p->dir_x * cos(rotspeed) - p->dir_y * sin(rotspeed);
	p->dir_y = tmp_x * sin(rotspeed) + p->dir_y * cos(rotspeed);
	tmp_x = p->plane_x;
	p->plane_x = p->plane_x * cos(rotspeed) - p->plane_y * sin(rotspeed);
	p->plane_y = tmp_x * sin(rotspeed) + p->plane_y * cos(rotspeed);
	return (1);
}
