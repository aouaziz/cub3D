/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 11:14:33 by aouaziz           #+#    #+#             */
/*   Updated: 2023/08/03 07:22:27 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_cube	*check_And_Set_Player_Position(t_cube *cube)
{
	int	i;
	int	j;

	i = 0;
	while (cube->mapinfo.file[i])
	{
		j = 0;
		while (cube->mapinfo.file[i][j])
		{
			if (cube->mapinfo.file[i][j] == 'N' || cube->mapinfo.file[i][j] == 'S'
				|| cube->mapinfo.file[i][j] == 'W' ||
				cube->mapinfo.file[i][j] == 'E')
				cube->player.dir = cube->mapinfo.file[i][j];
			j++;
		}
		i++;
	}
	cube = find_Player_Position(cube);
	return (cube);
}

t_cube	*find_Player_Position(t_cube *cube)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (cube->mapinfo.file[i])
	{
		j = 0;
		while (cube->mapinfo.file[i][j])
		{
			if (cube->mapinfo.file[i][j] == cube->player.dir)
				break ;
			j++;
		}
		if (cube->mapinfo.file[i][j] == cube->player.dir)
			break ;
		i++;
	}
	cube->player.pos_x = i;
	cube->player.pos_y = j + 1;
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