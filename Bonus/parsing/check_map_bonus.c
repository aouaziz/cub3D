/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 07:19:58 by aouaziz           #+#    #+#             */
/*   Updated: 2023/08/03 16:18:48 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"


t_cube	*check_Map_Lines_bonus(t_cube *cube)
{
	cube = check_And_Set_Player_Position_bonus(cube);
	cube = get_Map_width_And_Height_bonus(cube);
	return (cube);
}
void	check_map_errors_bonus(int fd, t_cube *cube)
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
		if (j == 0 && start_Checking_bonus(line, 0))
			j++;
		else if (j > 0)
			map[++i] = ft_cub_strdup(line, cube->mapinfo.width + 1);
		free(line);
	}
	close(fd);
	free(line);
	start_Checking_bonus(NULL, 1);
	check_Map_Not_Closed_bonus(map);
}
void	check_Map_error_Line_bonus(char **line, int x)
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
int	ft_skip_new_line_bonus(char **line, int y)
{
	if(!line[0])
		ft_print_error("Invalid Map\n");
	while (line [y] && line[y][0] == '\n')
		y++;
	return (y);
}
