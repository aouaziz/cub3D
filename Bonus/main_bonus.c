/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 09:56:46 by aouaziz           #+#    #+#             */
/*   Updated: 2023/08/01 14:12:13 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	start_Map_bonus(t_cube *cube)
{
	if (cube->map[0] == NULL)
		ft_print_error("Invalid Map\n");
	cube = check_Map_Lines_bonus(cube);
	print_cube3d_bonus(cube);
	exit(0);
	cube->mlx = mlx_init();
	cube->win = mlx_new_window(cube->mlx, cube->win_width, cube->win_height, "Cub3D");
	 if(cube->win == NULL)
		 ft_print_error("Error: something wrong !!!");
	// ft_mini_map(cube);
    //ft_put_mini_map(cube);
	// init_textures(cube);
	// render_images(cube);
	// listen_for_input(cube);
	// mlx_loop_hook(cube->mlx, engine, cube);
	// mlx_loop(cube->mlx);
}

// void	ft_mini_map(t_cube *cube)
// {
// 	int i;
// 	int j;
	
// 	i = 0;
// 	while (cube->map[i])
// 	{
// 		j = 0;
// 		while (cube->map[i][j])
// 		{
// 			if(cube->map[i][j] == cube->player.dir)
// 				ft_start_drawing(cube, i, j);
// 			j++;
// 		}
// 		i++;
// 	}
// }

// void ft_start_drawing(t_cube *cube,int i, int j)
// {
// 	int x;
// 	int y;

// 	x = i - 5;
// 	y = j - 5;
// 	while ( cube->map[x])
// 	{
// 		if(x == i + 5)
// 			break;
// 		y = j - 5;
// 		while (cube->map[x][y] && y < j - 5)
// 		{
// 			if (cube->map[x][y] == '1')
// 				ft_mlx_put_color(cube->mlx, cube->win,, x, y);
// 			else if (cube->map[x][y] == cube->player.dir)
// 				ft_mlx_put_color(cube->mlx, cube->win, x, y);
// 			else if (cube->map[x][y] == 'D')
// 				ft_mlx_put_color(cube->mlx, cube->win, x, y);
// 			else if (cube->map[x][y] == '0')
// 				ft_mlx_put_color(cube->mlx, cube->win, x, y);
// 			y++;
// 		}
// 		x++;
// 	}
// }

// void	ft_mlx_put_color(void *mlx_ptr, void *mlx_win, char *color,int x, int y)
// {
// 	t_so_long	s;
// 	void		*mlx_wall;

// 	mlx_wall = mlx_xpm_file_to_image(mlx_ptr, "./assets/XPM/1and0/1.xpm", &s.y,
// 			&s.x);
// 	if (mlx_wall == NULL)
// 		ft_image_error();
// 	mlx_put_image_to_window(mlx_ptr, mlx_win, mlx_wall, x * 50, y * 50);
// }