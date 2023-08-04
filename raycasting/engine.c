#include "../includes/cub3d.h"

void	calculate_line_height(t_ray *ray, t_cube *cube, t_player *player)
{
	if (ray->side == 0)
		ray->wall_dist = (ray->sidedist_x - ray->deltadist_x);
	else
		ray->wall_dist = (ray->sidedist_y - ray->deltadist_y);
	ray->line_height = (int)(cube->win_height / ray->wall_dist);
	ray->draw_start = -(ray->line_height) / 2 + cube->win_height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + cube->win_height / 2;
	if (ray->draw_end >= cube->win_height)
		ray->draw_end = cube->win_height - 1;
	if (ray->side == 0)
		ray->wall_x = player->pos_y + ray->wall_dist * ray->dir_y;
	else
		ray->wall_x = player->pos_x + ray->wall_dist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
}

void	set_RC(t_ray *ray, t_player *player)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->sidedist_x = (player->pos_x - ray->map_x) * ray->deltadist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = (ray->map_x + 1.0 - player->pos_x) * ray->deltadist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (player->pos_y - ray->map_y) * ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = (ray->map_y + 1.0 - player->pos_y) * ray->deltadist_y;
	}
}

void	perform_RC(t_cube *cube, t_ray *ray)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_y < 0.25 || ray->map_x < 0.25
			|| ray->map_y > cube->mapinfo.height - 0.25
			|| ray->map_x > cube->mapinfo.width - 1.25)
			break ;
		else if (cube->map[ray->map_y][ray->map_x] > '0')
			hit = 1;
	}
}

int	raycasting(t_player *player, t_cube *cube)
{
	t_ray	ray;
	int		x;

	x = 0;
	ray = cube->ray;
	while (x < cube->win_width)
	{
		init_raycasting_info(x, &ray, player);
		set_RC(&ray, player);
		perform_RC(cube, &ray);
		calculate_line_height(&ray, cube, player);
		update_texture_pixels(cube, &cube->texinfo, &ray, x);
		x++;
	}
	return (0);
}

void	render_images(t_cube *cube)
{
	init_texture_pixels(cube);
	init_ray(&cube->ray);
	raycasting(&cube->player, cube);
	render_frame(cube);
	render_minimap(cube);
}