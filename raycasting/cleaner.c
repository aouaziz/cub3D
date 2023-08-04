#include "../includes/cub3d.h"

void	free_tab(void **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	if (tab)
	{
		free(tab);
		tab = NULL;
	}
}

void	free_texinfo(t_texinfo *textures)
{
	if (textures->north)
		free(textures->north);
	if (textures->south)
		free(textures->south);
	if (textures->west)
		free(textures->west);
	if (textures->east)
		free(textures->east);
	if (textures->floor)
		free(textures->floor);
	if (textures->ceiling)
		free(textures->ceiling);
}

void	free_map(t_cube *cube)
{
	if (cube->mapinfo.fd > 0)
		close(cube->mapinfo.fd);
	if (cube->mapinfo.file)
		free_tab((void **)cube->mapinfo.file);
	if (cube->map)
		free_tab((void **)cube->map);
}

int	free_cube(t_cube *cube)
{
	if (cube->textures)
		free_tab((void **)cube->textures);
	if (cube->texture_pixels)
		free_tab((void **)cube->texture_pixels);
	free_texinfo(&cube->texinfo);
	free_map(cube);
	return (1);
}

void	clean_exit(t_cube *cube, int code)
{
	if (!cube)
		exit(code);
	if (cube->win && cube->mlx)
		mlx_destroy_window(cube->mlx, cube->win);
	if (cube->mlx)
	{
		/*mlx_destroy_display(cube->mlx);
		mlx_loop_end(cube->mlx);*/
		free(cube->mlx);
	}
	free_cube(cube);
	exit(code);
}