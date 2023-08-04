#include "../includes/cub3d.h"

void	set_minimap_tile_pixels(t_minimap *minimap, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < minimap->tile_size)
	{
		j = 0;
		while (j < minimap->tile_size)
		{
			set_image_pixel(minimap->img, x + j, i + y, color);
			j++;
		}
		i++;
	}
}

void	draw_minimap_tile(t_minimap *minimap, int x, int y)
{
	if (minimap->map[y][x] == 'P')
		set_minimap_tile_pixels(minimap, x * minimap->tile_size, y
				* minimap->tile_size, MM_COLOR_PLAYER);
	else if (minimap->map[y][x] == '1')
		set_minimap_tile_pixels(minimap, x * minimap->tile_size, y
				* minimap->tile_size, MM_COLOR_WALL);
	else if (minimap->map[y][x] == '0')
		set_minimap_tile_pixels(minimap, x * minimap->tile_size, y
				* minimap->tile_size, MM_COLOR_FLOOR);
	else if (minimap->map[y][x] == ' ')
		set_minimap_tile_pixels(minimap, x * minimap->tile_size, y
				* minimap->tile_size, MM_COLOR_SPACE);
}

void	set_minimap_border_image_pixels(t_minimap *minimap, int color)
{
	int	size;
	int	x;
	int	y;

	size = MM_PIXEL_SIZE + minimap->tile_size;
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x <= size)
		{
			if (x < 5 || x > size - 5 || y < 5 || y > size - 5)
				set_image_pixel(minimap->img, x, y, color);
			x++;
		}
		y++;
	}
}

void	draw_minimap(t_minimap *minimap)
{
	int	x;
	int	y;

	y = 0;
	while (y < minimap->size)
	{
		x = 0;
		while (x < minimap->size)
		{
			if (!minimap->map[y] || !minimap->map[y][x]
				|| minimap->map[y][x] == '\0')
				break ;
			draw_minimap_tile(minimap, x, y);
			x++;
		}
		y++;
	}
	set_minimap_border_image_pixels(minimap, MM_COLOR_SPACE);
}

void	render_minimap_image(t_cube *cube, t_minimap *minimap)
{
	int img_size;

	img_size = MM_PIXEL_SIZE + minimap->tile_size;
	init_img(cube, &cube->minimap, img_size, img_size);
	draw_minimap(minimap);
	mlx_put_image_to_window(cube->mlx, cube->win, cube->minimap.img,
			minimap->tile_size, cube->win_height - (MM_PIXEL_SIZE
				+ (minimap->tile_size * 2)));
	mlx_destroy_image(cube->mlx, cube->minimap.img);
}