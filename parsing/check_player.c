/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 11:14:33 by aouaziz           #+#    #+#             */
/*   Updated: 2023/08/06 04:13:02 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_cube	*check_and_set_player_position(t_cube *cube)
{
	int	i;
	int	j;

	i = 0;
	while (cube->map[i])
	{
		j = 0;
		while (cube->map[i][j])
		{
			if (cube->map[i][j] == 'N' || cube->map[i][j] == 'S'
				|| cube->map[i][j] == 'W' ||
				cube->map[i][j] == 'E')
				cube->player.dir = cube->map[i][j];
			j++;
		}
		i++;
	}
	cube = find_player_position(cube);
	return (cube);
}

t_cube	*find_player_position(t_cube *cube)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (cube->map[i])
	{
		j = 0;
		while (cube->map[i][j])
		{
			if (cube->map[i][j] == cube->player.dir)
			{
				cube->player.pos_x = i + 0.5;
				cube->player.pos_y = j + 0.5;
				return (cube);
			}
			j++;
		}
		i++;
	}
	return (cube);
}

void	validate_player_position(char **map, int i, int j)
{
	if (map[i + 1][j] != '0' && map[i + 1][j] != '1')
		ft_print_error("Invalid Map - Incorrect Player Position\n");
	else if (map[i - 1][j] != '0' && map[i - 1][j] != '1')
		ft_print_error("Invalid Map - Incorrect Player Position\n");
	else if (map[i][j + 1] != '0' && map[i][j + 1] != '1')
		ft_print_error("Invalid Map - Incorrect Player Position\n");
	else if (map[i][j - 1] != '0' && map[i][j - 1] != '1')
		ft_print_error("Invalid Map - Incorrect Player Position\n");
}
