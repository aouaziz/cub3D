#ifndef CUB3D_H
# define CUB3D_H

# include "../parsing/libft/includes/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
#include <mlx.h>
//# include <X11/keysym.h>
// # include <X11/X.h>
//# include "minilibx-linux/mlx.h"

# define SPEED 0.0125
# define ESC_KEY 53
# define S_KEY 1
# define A_KEY 2
# define W_KEY 13
# define D_KEY 0
# define RIGHT_ARROW 123
# define LEFT_ARROW 124
# define MM_PIXEL_SIZE 128
# define MM_VIEW 4
# define MM_COLOR_PLAYER 0x00FF00
# define MM_COLOR_WALL 0x808080
# define MM_COLOR_FLOOR 0xE6E6E6
# define MM_COLOR_SPACE 0x404040
# define SCREEN_WIDTH 640
# define SCREEN_HEIGHT 480
# define ROT 0.015

# define TEX 64

enum				e_index
{
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3
};

# ifndef O_DIRECTORY
#  define O_DIRECTORY 00200000
# endif

typedef struct s_img
{
	void			*img;
	int				*addr;
	int				pixel_bits;
	int				size_line;
	int				endian;
}					t_img;

typedef struct s_texinfo
{
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	int				floor;
	int				ceiling;
	unsigned long	hex_floor;
	unsigned long	hex_ceiling;
	int				size;
	int				index;
	double			step;
	double			pos;
	int				x;
	int				y;
}					t_texinfo;

typedef struct s_minimap
{
	char			**map;
	t_img			*img;
	int				size;
	int				offset_x;
	int				offset_y;
	int				view_dist;
	int				tile_size;
}					t_minimap;

typedef struct s_mapinfo
{
	int				fd;
	int				line_count;
	char			*path;
	char			**file;
	int				height;
	int				width;
	int				index_end_of_map;
}					t_mapinfo;

typedef struct s_ray
{
	double			camera_x;
	double			dir_x;
	double			dir_y;
	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
	double			sidedist_x;
	double			sidedist_y;
	double			deltadist_x;
	double			deltadist_y;
	double			wall_dist;
	double			wall_x;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
}					t_ray;

typedef struct s_player
{
	char			dir;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	int				has_moved;
	int				move_x;
	int				move_y;
	int				rotate;
}					t_player;

typedef struct s_cube
{
	void			*mlx;
	void			*win;
	int				win_height;
	int				win_width;
	t_mapinfo		mapinfo;
	char			**map;
	char			*t_map;
	t_player		player;
	t_ray			ray;
	int				**texture_pixels;
	int				**textures;
	t_texinfo		texinfo;
	t_img			minimap;
}					t_cube;

int					engine(t_cube *cube);
void				init_mlx(t_cube *cube);
void				clean_exit(t_cube *cube, int code);
int					free_cube(t_cube *cube);
void				free_map(t_cube *cube);
void				free_texinfo(t_texinfo *textures);
void				free_tab(void **tab);
void				set_image_pixel(t_img *image, int x, int y, int color);
void				set_frame_image_pixel(t_cube *cube, t_img *image, int x,
						int y);
void				init_img(t_cube *cube, t_img *image, int width, int height);
void				render_frame(t_cube *cube);
void				render_images(t_cube *cube);
int					raycasting(t_player *player, t_cube *cube);
void				perform_RC(t_cube *cube, t_ray *ray);
void				set_RC(t_ray *ray, t_player *player);
void				calculate_line_height(t_ray *ray, t_cube *cube,
						t_player *player);
void				init_cube(t_cube *cube);
void				init_img_clean(t_img *img);
void				init_ray(t_ray *ray);
void				init_mapinfo(t_mapinfo *mapinfo);
void				init_player(t_player *player);
void				listen_for_input(t_cube *cube);
int					key_release(int key, t_cube *cube);
int					key_press(int key, t_cube *cube);
int					ft_quit(t_cube *cube);
void				render_minimap(t_cube *cube);
int					get_MM_offset(t_minimap *minimap, int mapsize, int pos);
char				**generate_minimap(t_cube *cube, t_minimap *minimap);
char				*add_minimap_line(t_cube *cube, t_minimap *m, int y);
bool				is_valid_map_coord(int coord, int size);
void				render_minimap_image(t_cube *cube, t_minimap *minimap);
void				draw_minimap(t_minimap *minimap);
void	set_minimap_border_image_pixels(t_minimap *minimap,
										int color);
void				draw_minimap_tile(t_minimap *minimap, int x, int y);
void				set_minimap_tile_pixels(t_minimap *minimap, int x, int y,
						int color);
bool				is_valid_pos_wall_collision(t_cube *cube, double x,
						double y);
bool				is_valid_pos_in_map(t_cube *cube, double x, double y);
bool				is_valid_pos(t_cube *cube, double x, double y);
int					ft_move(t_cube *cube, double new_x, double new_y);
int					rotate_left_right(t_cube *cube, double rotspeed);
int					rotate(t_cube *cube, double rotdir);
int					move_player(t_cube *cube);
void				init_texture_pixels(t_cube *cube);
void				init_texture_img(t_cube *cube, t_img *image, char *path);
int					*xpm_to_img(t_cube *cube, char *path);
void				init_textures(t_cube *cube);
void				init_texinfo(t_texinfo *textures);
void				get_texture_index(t_cube *cube, t_ray *ray);
void				update_texture_pixels(t_cube *cube, t_texinfo *tex,
						t_ray *ray, int x);
void				init_raycasting_info(int x, t_ray *ray, t_player *player);
void				errMsg(char *message);

//parsing file
int					ft_cub(char *c, int i);
void				check_File_And_Read_it(char *file, t_cube *cube);

//reading map
void				Parse_map(t_cube *cube);
void				start_Map(t_cube *cube);
void				check_Map_Height_And_Width(char **map);
t_cube				*get_Map_Height(t_cube *cube, int fd);
int					get_Map_width(char *line);
t_cube				*get_Map_width_And_Height(t_cube *cube);

//check map error
t_cube				*check_Map_Lines(t_cube *cube);
int					ft_check_char(char c);
void				check_Zero_Surroundings(char **map);
void				check_Map_Not_Closed(char **map);
int					start_Map_Check(t_cube *cube);
int					ft_skip_new_line(char **line, int y);
int					start_Checking(char *line, int finish);
void				check_map_errors(int fd, t_cube *cube);
void				ft_check_is_map_empty(char **map);
void				ft_Unknown_Character_in_Map(char **map);
void				validate_Zero_Position(char **map, int i, int j);

// check player error
t_cube				*check_And_Set_Player_Position(t_cube *cube);
t_cube				*find_Player_Position(t_cube *cube);
void				validate_Player_Position(char **map, int i, int j);
void				check_Player_error(char **map);

//color and textur
t_cube				*cube_textur_color(t_cube *cube, char *line);
t_cube				*get_Texture(t_cube *cube, char *line);
t_cube				*get_Color(t_cube *cube, char *line);
t_cube				*add_textur(t_cube *cube, char *content, int type);

// check lines error
void				ft_check_new_line_error(char **map, int y);
void				check_Map_error_Line(char **line, int x);
void				check_First_last_Line(char *line);

// print stract
void				print_textur(t_texinfo *textur);
void				print_cube3d(t_cube *cube);
void				print_str(char **str);
#endif