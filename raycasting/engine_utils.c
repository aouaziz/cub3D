/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 22:53:01 by mmalih            #+#    #+#             */
/*   Updated: 2023/08/06 03:34:15 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_image_pixel(t_img *image, int x, int y, int color)
{
	int	pixel;

	pixel = y * (image->size_line / 4) + x;
	image->addr[pixel] = color;
}

void	set_frame_image_pixel(t_cube *cube, t_img *image, int x, int y)
{
	if (cube->texture_pixels[y][x] > 0)
		set_image_pixel(image, x, y, cube->texture_pixels[y][x]);
	else if (y < cube->win_height / 2)
		set_image_pixel(image, x, y, cube->texinfo.hex_ceiling);
	else if (y < cube->win_height - 1)
		set_image_pixel(image, x, y, cube->texinfo.hex_floor);
}

void	init_img(t_cube *cube, t_img *image, int width, int height)
{
	init_img_clean(image);
	image->img = mlx_new_image(cube->mlx, width, height);
	if (image->img == NULL)
	{
		printf("image Error\n");
		clean_exit(cube, 1);
	}
	image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits,
			&image->size_line, &image->endian);
	return ;
}

void	render_frame(t_cube *cube)
{
	t_img	image;
	int		x;
	int		y;

	image.img = NULL;
	init_img(cube, &image, cube->win_width, cube->win_height);
	y = 0;
	while (y < cube->win_height)
	{
		x = 0;
		while (x < cube->win_width)
		{
			set_frame_image_pixel(cube, &image, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(cube->mlx, cube->win, image.img, 0, 0);
	mlx_destroy_image(cube->mlx, image.img);
}
