/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 03:23:43 by aouaziz           #+#    #+#             */
/*   Updated: 2023/08/06 04:16:23 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_buffer_error(int *buffer, t_cube *cube)
{
	if (!buffer)
	{
		printf("Error\n");
		clean_exit(cube, 1);
	}
}

int	rotate(t_cube *cube, double rotdir)
{
	int		moved;
	double	rotspeed;

	moved = 0;
	rotspeed = ROT * rotdir;
	moved += rotate_left_right(cube, -rotspeed);
	return (moved);
}
