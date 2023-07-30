/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_textur.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:07:04 by aouaziz           #+#    #+#             */
/*   Updated: 2023/07/30 14:53:55 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_cube	*cube_textur_color(t_cube *cube, char *line)
{
	cube = get_Texture(cube, line);
	cube = get_Color(cube, line);
	return (cube);
}

t_cube	*get_Texture(t_cube *cube, char *line)
{
	char	**str;

	if (ft_strchr(line, '\t'))
		ft_print_error("Invalid Map - Tab Character Found\n");
	str = ft_split(line, ' ');
	if (!ft_strcmp(str[0], "NO "))
		cube = add_textur(cube, str[1], NORTH);
	else if (!ft_strcmp(str[0], "SO "))
		cube = add_textur(cube, str[1], SOUTH);
	else if (!ft_strcmp(str[0], "WE "))
		cube = add_textur(cube, str[1], WEST);
	else if (!ft_strcmp(str[0], "EA "))
		cube = add_textur(cube, str[1], EAST);
	free_double_str(str);
	return (cube);
}

t_cube	*get_Color(t_cube *cube, char *line)
{
	char	**str;
	char	*tmp;

	str = ft_split(line, ' ');
	tmp = ft_strtrim(line, " ");
	if (!ft_strncmp(str[0], "F", 2))
	{
		cube->texinfo.floor = ft_color_resolution(tmp + 1);
		cube->texinfo.size++;
	}
	else if (!ft_strncmp(str[0], "C", 2))
	{
		cube->texinfo.ceiling = ft_color_resolution(tmp + 1);
		cube->texinfo.size++;
	}
	if (cube->texinfo.size > 2)
		ft_print_error("Invalid Color Parameter\n");
	free_double_str(str);
	free(tmp);
	return (cube);
}
t_cube	*add_textur(t_cube *cube, char *content, int type)
{
	if (type == NORTH)
		cube->texinfo.north = ft_strdup(content);
	else if (type == SOUTH)
		cube->texinfo.south = ft_strdup(content);
	else if (type == WEST)
		cube->texinfo.west = ft_strdup(content);
	else if (type == EAST)
		cube->texinfo.east = ft_strdup(content);
	return (cube);
}