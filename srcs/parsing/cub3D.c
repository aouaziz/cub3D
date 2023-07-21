/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:55:46 by aouaziz           #+#    #+#             */
/*   Updated: 2023/07/21 15:43:33 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

t_cube3d	*get_textur(t_cube3d *cube, char *line)
{
	char	**str;


	if (ft_strchr(line, '\t'))
		ft_print_error(1);
	str = ft_split(line, ' ');
	if (!ft_strncmp(str[0], "NO", 3))
		cube = add_textur_to_list(cube, str[1], NO);
	else if (!ft_strncmp(str[0], "SO", 3))
		cube = add_textur_to_list(cube, str[1], SO);
	else if (!ft_strncmp(str[0], "WE", 3))
		cube = add_textur_to_list(cube, str[1], WE);
	else if (!ft_strncmp(str[0], "EA", 3))
		cube = add_textur_to_list(cube, str[1], EA);
	return (cube);
}

t_cube3d	*get_color(t_cube3d *cube, char *line)
{
	char	**str;
	static int i ;


	str = ft_split(line, ' ');
	if (!ft_strncmp(str[0], "F", 2))
	{
		cube->F = ft_color_resolution(str[1]);
		i++;
	}
	else if (!ft_strncmp(str[0], "C", 2))
	{
		cube->C = ft_color_resolution(str[1]);
		i++;
	}
	if(i > 2)
		ft_print_error(2);
	return (cube);
}
int ft_start(t_cube3d *cube)
{
	if (ft_lstsize_textur(cube->textur) == 4 && cube->F != 0 && cube->C != 0)
		return (1);
	return (0);
}
t_cube3d *ft_fill_map(t_cube3d *cube, char *line)
{
	
}

void	read_file(t_cube3d *cube, int fd)
{
	char	*line;
	
	// Read lines using get_next_line
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (line[0] != '\n')
		{
			cube = get_textur(cube, line);
			cube = get_color(cube, line);
		}
		else if(ft_start(cube))
			cube = ft_fill_map(cube, line);
		free(line);
	}
	// Add NULL terminator to mark the end of the map
	//cube->map[line_count] = NULL;
}

void	ft_check_file(char *file, t_cube3d *cube)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (!ft_cub(file, ft_strlen(file)) || fd < 1)
		ft_print_error(1);
	read_file(cube, fd);
}

int	main(int ac, char *av[])
{
	t_cube3d	*cube;

	cube = malloc(sizeof(t_cube3d));
	cube->textur = NULL;
	cube->F = 0;
	cube->C = 0;
	cube->i = 0;
	if (ac == 2)
		ft_check_file(av[1], cube);
	else
		ft_print_error(1);
}
