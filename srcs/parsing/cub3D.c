/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:55:46 by aouaziz           #+#    #+#             */
/*   Updated: 2023/07/11 11:24:39 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3D.h"


void get_textur(t_cube3d *cube, char *line)
{
	char *str;
	str = ft_strtrim(line, " ");
	free(line);
	line = ft_strjoin(str, "\n");
	free (str);
	if(line[0] == 'N')
		cube->textur=add_textur_to_list(cube->textur, line, NO);
	else if(line[0] == 'S')
		cube->textur=add_textur_to_list(cube->textur, line, SO);
	else if(line[0] == 'W')
		cube->textur=add_textur_to_list(cube->textur, line, WE);
	else if(line[0] == 'E')
		cube->textur=add_textur_to_list(cube->textur, line, EA);
	cube->i = 1;
}

void get_color(t_cube3d *cube, char *line)
{
	char *str;
	if(cube->i)
		return ;
	str = ft_strtrim(line, " ");
	free(line);
	line = ft_strjoin(str, "\n");
	free (str);
	if(line[0] == 'F')
		cube->F = ft_color_resolution(line);
	else if(line[0] == 'C')
		cube->C = ft_color_resolution(line);
	
}

void	read_file(t_cube3d *cube,int fd)
{
	char *line;
	int line_count = 0;

	// Read lines using get_next_line
	while (1)
	 {
		line = get_next_line(fd);
		if (line == NULL)
			break;
		get_textur(cube, line);
		get_color(cube, line);
		cube->map[line_count] = cube->str ;
		free(line);
		free(cube->str);
		line_count++;
	}
	// Add NULL terminator to mark the end of the map
	cube->map[line_count] = NULL;
}

void	ft_check_file(char *file, t_cube3d *cube)
{
	int fd;
	printf("file %s\n",file);
	fd = open(file, O_RDONLY);
	printf("fd %d\n",fd);
	if(!ft_cub(file, ft_strlen(file)) || fd < 1 )
		ft_print_error(1);
	read_file(cube,fd);
}


int main(int ac , char *av[])
{
	t_cube3d *cube;
	cube = malloc(sizeof(t_cube3d));
	if(ac == 2)
		ft_check_file(av[1], cube);
	else 
		ft_print_error(1);
}
