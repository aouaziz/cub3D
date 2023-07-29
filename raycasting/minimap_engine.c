#include "../includes/cub3d.h"

bool	is_valid_map_coord(int coord, int size)
{
	if (coord < size)
		return (true);
	return (false);
}

char	*add_minimap_line(t_cube *cube, t_minimap *m, int y)
{
	char	*line;
	int		x;

	line = ft_calloc(m->size + 1, sizeof * line);
	if (!line)
		return (NULL);
	x = 0;
	while (x < m->size && x < cube->mapinfo.width)
	{
		if (!is_valid_map_coord(y + m->offset_y, cube->mapinfo.height)
			|| !is_valid_map_coord(x + m->offset_x, cube->mapinfo.width))
			line[x] = '\0';
		else if ((int)cube->player.pos_x == (x + m->offset_x)
			&& (int)cube->player.pos_y == (y + m->offset_y))
			line[x] = 'P';
		else if (cube->map[y + m->offset_y][x + m->offset_x] == '1')
			line[x] = '1';
		else if (cube->map[y + m->offset_y][x + m->offset_x] == '0')
			line[x] = '0';
		else
			line[x] = '\0';
		x++;
	}
	return (line);
}

char	**generate_minimap(t_cube *cube, t_minimap *minimap)
{
	char	**mmap;
	int		y;

	mmap = ft_calloc(minimap->size + 1, sizeof * mmap);
	if (!mmap)
		return (NULL);
	y = 0;
	while (y < minimap->size && y < cube->mapinfo.height)
	{
		mmap[y] = add_minimap_line(cube, minimap, y);
		if (!mmap[y])
		{
			free_tab((void **)mmap);
			return (NULL);
		}
		y++;
	}
	return (mmap);
}

int	get_MM_offset(t_minimap *minimap, int mapsize, int pos)
{
	if (pos > minimap->view_dist && mapsize - pos > minimap->view_dist + 1)
		return (pos - minimap->view_dist);
	if (pos > minimap->view_dist && mapsize - pos <= minimap->view_dist + 1)
		return (mapsize - minimap->size);
	return (0);
}

void	render_minimap(t_cube *cube)
{
	t_minimap	minimap;

	minimap.map = NULL;
	minimap.img = &cube->minimap;
	minimap.view_dist = MM_VIEW;
	minimap.size = (2 * minimap.view_dist) + 1;
	minimap.tile_size = MM_PIXEL_SIZE / (2 * minimap.view_dist);
	minimap.offset_x = get_MM_offset(&minimap,
			cube->mapinfo.width, (int)cube->player.pos_x);
	minimap.offset_y = get_MM_offset(&minimap,
			cube->mapinfo.height, (int)cube->player.pos_y);
	minimap.map = generate_minimap(cube, &minimap);
	if (!minimap.map)
	{
		errMsg("Error\nFailed to generate minimap");
		return ;
	}
	render_minimap_image(cube, &minimap);
	free_tab((void **)minimap.map);
}