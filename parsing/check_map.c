/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 07:19:58 by aouaziz           #+#    #+#             */
/*   Updated: 2023/07/29 11:31:50 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


int	ft_check_char(char c)
{
	if (c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (0);
	return (1);
}

t_cube	*check_Map_Lines(t_cube *cube)
{
	cube = check_And_Set_Player_Position(cube);
	cube = get_Map_width_And_Height(cube);
	return (cube);
}
void	check_map_errors(int fd ,t_cube *cube)
{
	char	*line;
	int i;
	int j;
	char **map;

	i = -1;
	j = 0;
	map = ft_calloc(cube->win_height, sizeof(char *));
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if(j == 0 && start_Checking(line,0))
			j++;
		else if (j>0)
			map[++i] = ft_cub_strdup(line, cube->win_width + 1);
		free(line);
	}
	close(fd);
	free(line);
	start_Checking(NULL, 1);
	check_Map_Not_Closed(map);
}
