/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3D.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:55:46 by aouaziz           #+#    #+#             */
/*   Updated: 2023/07/08 08:52:46 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3D.h"

void ft_skip_spaces(t_cube3d *cube)
{
	while(*cube->str == ' ' || *cube->str == '\n')
		cube++;
}
int ft_check_map(t_cube3d *cube)
{
	if (!ft_strchr(cube->str, '\t'))
		ft_print_error(2);
	while (cube->str)
	{
		ft_skip_spaces(cube);
		if(!ft_strncmp(cube->str, "NO ", 3))
		{
			
		}
	}
	
}
void	ft_check_file(char *file)
{
	t_cube3d cube;
	char *line;
	
	line = NULL;
	cube.len = ft_strlen(file);
	cube.file->fd = open(file, O_RDONLY);
	if(!cube.len || !ft_cub(file, cube.len) || cube.file->fd <= 0 )
		ft_print_error(1);
	while(1)
	{
		cube.str = get_next_line(cube.file->fd);
		if(!cube.str)
			break;
		line = ft_strtrim(line,cube.str);
		free(cube.str);
	}
	if(!line)
		ft_print_error(2);
	cube.str = line;
	cube.i = 0;
	ft_check_map(&cube);
	
}


int main(int ac , char *av[])
{
	if(ac == 2)
		ft_check_file(av[1]);
	else 
		ft_print_error(1);
}
