/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 06:58:32 by aouaziz           #+#    #+#             */
/*   Updated: 2023/07/29 11:34:26 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


int	ft_cub(char *c, int i)
{
	if (c[i - 1] == 'b' && c[i - 2] == 'u' && c[i - 3] == 'c' && c[i
		- 4] == '.')
		return (1);
	else
		return (0);
}

int	start_Map_Check(t_cube *cube)
{
	static int	i;
	int j;

	j = 0;
	if(cube->texinfo.east != NULL)
		j++;
	if(cube->texinfo.west)
		j++;
	if(cube->texinfo.north)
		j++;
	if(cube->texinfo.south)
		j++;
	if ( j == 4 && cube->texinfo.size == 2 && i == 0)
	{
		i++;
		return (0);
	}
	else if (j == 4 && cube->texinfo.size == 2)
		return (1);
	return (0);
}
void	check_File_And_Read_it(char *file, t_cube *cube)
{
	int	fd;
	
	fd = open(file, O_RDONLY);
	if (!ft_cub(file, ft_strlen(file)) || fd < 1)
		ft_print_error("Invalid File\n");
	cube = get_Map_Height(cube, fd);
	fd = open(file, O_RDONLY);
	check_map_errors(fd,cube);
	Parse_map(cube);
}

