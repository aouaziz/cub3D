/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 11:14:33 by aouaziz           #+#    #+#             */
/*   Updated: 2023/07/29 11:34:01 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


t_cube	*check_And_Set_Player_Position(t_cube *cube)
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
	cube = find_Player_Position(cube);
	return (cube);
}

t_cube	*find_Player_Position(t_cube *cube)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (cube->map[i])
	{
		j = 0;
		while (cube->map[i][j])
		{
			if (cube->map[i][j] == cube->player.dir)
				break ;
			j++;
		}
		if (cube->map[i][j] == cube->player.dir)
			break ;
		i++;
	}
	cube->player.move_y = i;
	cube->player.move_x = j + 1;
	return (cube);
}
void	validate_Player_Position(char **map, int i, int j)
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