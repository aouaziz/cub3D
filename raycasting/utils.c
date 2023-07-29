#include "../includes/cub3d.h"

void	get_texture_index(t_cube *cube, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->dir_x < 0)
			cube->texinfo.index = WEST;
		else
			cube->texinfo.index = EAST;
	}
	else
	{
		if (ray->dir_y > 0)
			cube->texinfo.index = SOUTH;
		else
			cube->texinfo.index = NORTH;
	}
}

void	update_texture_pixels(t_cube *cube, t_texinfo *tex, t_ray *ray, int x)
{
	int			y;
	int			color;

	get_texture_index(cube, ray);
	tex->x = (int)(ray->wall_x * tex->size);
	if ((ray->side == 0 && ray->dir_x < 0)
		|| (ray->side == 1 && ray->dir_y > 0))
		tex->x = tex->size - tex->x - 1;
	tex->step = 1.0 * tex->size / ray->line_height;
	tex->pos = (ray->draw_start - cube->win_height / 2
			+ ray->line_height / 2) * tex->step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		tex->y = (int)tex->pos & (tex->size - 1);
		tex->pos += tex->step;
		color = cube->textures[tex->index][tex->size * tex->y + tex->x];
		if (tex->index == NORTH || tex->index == EAST)
			color = (color >> 1) & 8355711;
		if (color > 0)
			cube->texture_pixels[y][x] = color;
		y++;
	}
}

void	init_raycasting_info(int x, t_ray *ray, t_player *player)
{
	init_ray(ray);
	ray->camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
	ray->dir_x = player->dir_x + player->plane_x * ray->camera_x;
	ray->dir_y = player->dir_y + player->plane_y * ray->camera_x;
	ray->map_x = (int)player->pos_x;
	ray->map_y = (int)player->pos_y;
	ray->deltadist_x = fabs(1 / ray->dir_x);
	ray->deltadist_y = fabs(1 / ray->dir_y);
}

void	errMsg(char *message)
{
	ft_putstr_fd("Error : \n", 1);
	ft_putstr_fd(message, 1);
	ft_putstr_fd("\n", 1);
	exit(EXIT_FAILURE);
}