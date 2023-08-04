#include "../includes/cub3d.h"

void	init_texture_pixels(t_cube *cube)
{
	int	i;

	if (cube->texture_pixels)
		free_tab((void **)cube->texture_pixels);
	cube->texture_pixels = ft_calloc(cube->win_height + 1,
										sizeof *cube->texture_pixels);
	if (!cube->texture_pixels)
		clean_exit(cube, 1);
	i = 0;
	while (i < cube->win_height)
	{
		cube->texture_pixels[i] = ft_calloc(cube->win_width + 1,
											sizeof *cube->texture_pixels);
		if (!cube->texture_pixels[i])
		{
			printf("texture_pixels Error\n");
			clean_exit(cube, 1);
		}
		i++;
	}
}

void	init_texture_img(t_cube *cube, t_img *image, char *path)
{
	init_img_clean(image);
	image->img = mlx_xpm_file_to_image(cube->mlx, path, &cube->texinfo.size,
			&cube->texinfo.size);
	if (image->img == NULL)
	{
		ft_print_error("Invalid Texture Path \n");
		//clean_exit(cube, 1);
	}
	image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits,
			&image->size_line, &image->endian);
	return ;
}

int	*xpm_to_img(t_cube *cube, char *path)
{
	t_img	tmp;
	int		*buffer;
	int		x;
	int		y;

	init_texture_img(cube, &tmp, path);
	buffer = ft_calloc(1,
						sizeof *buffer * cube->texinfo.size
							* cube->texinfo.size);
	if (!buffer)
	{
		printf("Error\n");
		clean_exit(cube, 1);
	}
	y = 0;
	while (y < cube->texinfo.size)
	{
		x = 0;
		while (x < cube->texinfo.size)
		{
			buffer[y * cube->texinfo.size + x] = tmp.addr[y * cube->texinfo.size
				+ x];
			++x;
		}
		y++;
	}
	mlx_destroy_image(cube->mlx, tmp.img);
	return (buffer);
}

void	init_textures(t_cube *cube)
{
	cube->textures = ft_calloc(5, sizeof *cube->textures);
	if (!cube->textures)
	{
		printf("textures Error\n");
		clean_exit(cube, 1);
	}
	cube->textures[NORTH] = xpm_to_img(cube, cube->texinfo.north);
	cube->textures[SOUTH] = xpm_to_img(cube, cube->texinfo.south);
	cube->textures[EAST] = xpm_to_img(cube, cube->texinfo.east);
	cube->textures[WEST] = xpm_to_img(cube, cube->texinfo.west);
	printf("Loading textures...\n");
}

void	init_texinfo(t_texinfo *textures)
{
	textures->north = NULL;
	textures->south = NULL;
	textures->west = NULL;
	textures->east = NULL;
	textures->floor = 0;
	textures->ceiling = 0;
	textures->hex_floor = 0x0;
	textures->hex_ceiling = 0x0;
	textures->size = TEX;
	textures->step = 0.0;
	textures->pos = 0.0;
	textures->x = 0;
	textures->y = 0;
}