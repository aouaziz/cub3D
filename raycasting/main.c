#include "../includes/cub3d.h"

void	init_mlx(t_cube *cube)
{
	cube->mlx = mlx_init();
	if (!cube->mlx)
		clean_exit(cube, 1);
	cube->win = mlx_new_window(cube->mlx, SCREEN_WIDTH, SCREEN_HEIGHT,
			"FPS_3D");
	if (!cube->win)
		clean_exit(cube, 1);
	return ;
}

void	start_Map(t_cube *cube)
{
	if (cube->map[0] == NULL)
		ft_print_error("Invalid Map\n");
	cube = check_Map_Lines(cube);
	init_mlx(cube);
	init_player_direction(cube);
	print_cube3d(cube);
	init_textures(cube);
	render_images(cube);
	listen_for_input(cube);
	mlx_loop_hook(cube->mlx, engine, cube);
	mlx_loop(cube->mlx);
}
