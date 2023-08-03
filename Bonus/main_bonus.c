/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 09:56:46 by aouaziz           #+#    #+#             */
/*   Updated: 2023/08/03 07:22:27 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	start_Map_bonus(t_cube *cube)
{
	if (cube->mapinfo.file[0] == NULL)
		ft_print_error("Invalid Map\n");
	cube = check_Map_Lines_bonus(cube);
	print_cube3d_bonus(cube);
	 cube->mlx = mlx_init();
	 cube->win = mlx_new_window(cube->mlx,1080, 1920, "Cub3D");
	if(cube->win == NULL)	
	   ft_print_error("Error: something wrong !!!");
	ft_mini_map(cube);
    // ft_put_mini_map(cube);
	// init_textures(cube);
	// render_images(cube);
	listen_for_input(cube);
	mlx_loop_hook(cube->mlx, engine, cube);
	mlx_loop(cube->mlx);
}
static void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;
	if (x >= 1080 || y >= 1920 )
	{
		return ;
	}
	
	dst = data->add + (y * data->size_line + x * (data->pixel_bits / 8));
	*(unsigned int*)dst = color;
}

// static void	ft_draw_squar(t_cube *cube, int i, int j)
// {
// 	int		x;
// 	int		y;
// 	int		color;

// 	y = j * 20;
// 	x = i * 20;
// 	color = 0x00FF0000;
// 	int z = 0;
// 	while (z < 20)
// 	{
// 		int w = x;
// 		while (w < 20)
// 		{
// 			my_mlx_pixel_put(&cube->minimap, y, w, color);
// 			printf("%d\n", y);
// 			w++;
// 		}
// 		z++;
// 		y++;
// 	}
// }

void	ft_mini_map(t_cube *cube)
{
	
	
	cube->minimap.img = mlx_new_image(cube->mlx, 1080, 1920);
	cube->minimap.add = mlx_get_data_addr(cube->mlx, &cube->minimap.pixel_bits, &cube->minimap.size_line, &cube->minimap.endian);
	printf("%d\n", cube->player.move_x);
	printf("%d\n", cube->player.move_y);
	ft_mlx_put_color(cube, 0x00FF0000, cube->player.move_x, cube->player.move_y);
	mlx_put_image_to_window(cube->mlx, cube->win, cube->minimap.img, 0, 0);
	
}

// void ft_start_drawing(t_cube *cube,int i, int j)
// {
// 
	// while ( cube->mapinfo.file[x])
	// {
		// if(x == i + 5)
			// break;
		// y = j - 5;
		// while (cube->mapinfo.file[x][y] && y < j + 5)
		// {
			// if (cube->mapinfo.file[x][y] == '1')
				// ft_mlx_put_color(cube->mlx, cube->win, 0x005E5C64, x, y);
			// else if (cube->mapinfo.file[x][y] == cube->player.dir)
				// ft_mlx_put_color(cube->mlx, cube->win,0x0000FF00, x, y);
			// else if (cube->mapinfo.file[x][y] == 'D')
				// ft_mlx_put_color(cube->mlx, cube->win,0x00FF0000, x, y);
			// else if (cube->mapinfo.file[x][y] == '0')
				// ft_mlx_put_color(cube->mlx, cube->win,0x008BB5F8, x, y);
			// y++;
		// }
		// x++;
	// }
// }
// 
void	ft_mlx_put_color(t_cube *cube, int color,int x, int y)
{
	int i;
	int j;

	i = y;
	while (i < y * Size)
	{
		j = x;
		while (j < x * Size)
		{
			
			my_mlx_pixel_put(&cube->minimap, j, i, color);
			j++;
		}
		i++;
	}
}