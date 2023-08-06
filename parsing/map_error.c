/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:28:18 by aouaziz           #+#    #+#             */
/*   Updated: 2023/08/06 04:12:21 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_map_not_closed(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = ft_skip_new_line(map, 0);
	ft_check_new_line_error(map, y);
	check_map_error_line(map, y);
	while (map[x])
		x++;
	x = x - 1;
	while (map[x][0] == '\n')
		x--;
	check_map_error_line(map, x);
	while (x != y)
	{
		check_first_last_line(ft_strtrim(map[x], " "));
		x--;
	}
	ft_unknown_character_in_map(map);
	check_zero_surroundings(map);
}

void	ft_unknown_character_in_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1' || map[i][j] == ' ' || map[i][j] == '0' ||
				map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W' ||
				map[i][j] == 'E' || map[i][j] == '\n')
				j++;
			else
				ft_print_error("Invalid Map - Unknown Character in Map\n");
		}
		i++;
	}
	check_player_error(map);
}

void	check_player_error(char **map)
{
	int	i;
	int	p;
	int	j;

	i = -1;
	p = 0;
	while (map[++i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W'
				|| map[i][j] == 'E')
			{
				validate_player_position(map, i, j);
				p++;
			}
			j++;
		}
	}
	if (p > 1)
		ft_print_error("Multiple Players Found in Map\n");
	if (p == 0)
		ft_print_error("Player Not Found in Map\n");
}

void	ft_check_is_map_empty(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		if (ft_strchr(map[i], '1'))
			j++;
		i++;
	}
	if (j == 0)
		ft_print_error("Invalid Map - Empty Map\n");
}

void	ft_check_new_line_error(char **map, int y)
{
	int	i;
	int	find;
	int	j;

	i = y;
	find = y;
	j = 0;
	ft_check_is_map_empty(map);
	while (map[i])
		i++;
	i--;
	while (i > 0 && map[i])
	{
		if (map[i][0] != '\n')
			break ;
		i--;
	}
	while (find > i && map[find])
	{
		if (map[find][0] != '\n')
			ft_print_error("Invalid Map - Empty Line in Map\n");
		find++;
	}
}
