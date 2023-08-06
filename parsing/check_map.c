/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 07:19:58 by aouaziz           #+#    #+#             */
/*   Updated: 2023/08/06 04:12:21 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_check_char(char c)
{
	if (c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (0);
	return (1);
}

t_cube	*check_map_lines(t_cube *cube)
{
	cube = check_and_set_player_position(cube);
	cube = get_map_width_and_height(cube);
	return (cube);
}

void	check_map_errors(int fd, t_cube *cube)
{
	char	*line;
	int		i;
	int		j;
	char	**map;

	i = -1;
	j = 0;
	map = ft_calloc(cube->mapinfo.height, sizeof(char *));
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (j == 0 && start_checking(line, 0))
			j++;
		else if (j > 0)
			map[++i] = ft_cub_strdup(line, cube->mapinfo.width + 1);
		free(line);
	}
	close(fd);
	free(line);
	start_checking(NULL, 1);
	check_map_not_closed(map);
}

void	check_map_error_line(char **line, int x)
{
	int	i;

	i = 0;
	while (line[x][i])
	{
		if (line[x][i] != '1' && line[x][i] != ' ' && line[x][i] != '\n')
			ft_print_error("Invalid Map - Map Not Closed\n");
		i++;
	}
}

int	ft_skip_new_line(char **line, int y)
{
	if (!line[0])
		ft_print_error("Invalid Map\n");
	while (line[y] && line[y][0] == '\n')
		y++;
	return (y);
}
