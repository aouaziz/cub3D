/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 16:49:31 by aouaziz           #+#    #+#             */
/*   Updated: 2023/08/06 04:13:55 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_cube	*get_map_height(t_cube *cube, int fd)
{
	char	*line;
	int		height;
	int		width;

	height = 0;
	width = 0;
	cube->t_map = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		cube->t_map = ft_strjoin(cube->t_map, line);
		width = ft_strlen(line);
		if (width > cube->mapinfo.width)
			cube->mapinfo.width = width;
		height++;
		free(line);
	}
	close(fd);
	cube->mapinfo.height = height;
	free(line);
	return (cube);
}

int	ft_get_len(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	parse_map(t_cube *cube)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	j = 0;
	cube->texinfo.size = 0;
	map = ft_split(cube->t_map, '\n');
	cube->map = malloc(sizeof(char *) * (ft_get_len(map) + 1));
	while (map[i])
	{
		if (j == 0)
			cube = cube_textur_color(cube, map[i]);
		if (start_map_check(cube))
		{
			cube->map[j] = ft_strdup(map[i]);
			j++;
		}
		i++;
	}
	free_double_str(map);
	cube->texinfo.size = TEX;
	cube->map[j] = NULL;
	start_map(cube);
}

int	start_checking(char *line, int finish)
{
	static int	status;

	if (finish == 1 && status != 6)
		ft_print_error("Error Missing some information\n");
	if (ft_strnstr(line, "NO ", ft_strlen(line)))
		status++;
	else if (ft_strnstr(line, "SO ", ft_strlen(line)))
		status++;
	else if (ft_strnstr(line, "WE ", ft_strlen(line)))
		status++;
	else if (ft_strnstr(line, "EA ", ft_strlen(line)))
		status++;
	else if (ft_strnstr(line, "F ", ft_strlen(line)))
		status++;
	else if (ft_strnstr(line, "C ", ft_strlen(line)))
		status++;
	if (status == 6)
		return (1);
	return (0);
}
