/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 06:58:32 by aouaziz           #+#    #+#             */
/*   Updated: 2023/08/06 04:07:40 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_cub(char *c, int i)
{
	if (c[i - 1] == 'b' && c[i - 2] == 'u' && c[i - 3] == 'c'
		&& c[i - 4] == '.')
		return (1);
	else
		return (0);
}

int	start_map_check(t_cube *cube)
{
	static int	i;
	int			j;

	j = 0;
	if (cube->texinfo.east)
		j++;
	if (cube->texinfo.west)
		j++;
	if (cube->texinfo.north)
		j++;
	if (cube->texinfo.south)
		j++;
	if (j == 4 && cube->texinfo.size == 2 && i == 0)
	{
		i++;
		return (0);
	}
	else if (j == 4 && cube->texinfo.size == 2)
		return (1);
	return (0);
}

void	check_file_and_read_it(char *file, t_cube *cube)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (!ft_cub(file, ft_strlen(file)) || fd < 1)
		ft_print_error("Invalid File\n");
	cube = get_map_height(cube, fd);
	fd = open(file, O_RDONLY);
	check_map_errors(fd, cube);
	parse_map(cube);
}
