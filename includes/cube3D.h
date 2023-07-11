/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:56:38 by aouaziz           #+#    #+#             */
/*   Updated: 2023/07/11 11:23:05 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "../libft/includes/libft.h"
# include <mlx.h>
enum				e_textur
{
	EA,
	NO,
	SO,
	WE,
};

typedef struct s_textur
{
	int				type;
	char			*file;
	struct s_textur	*next;
}					t_textur;

typedef struct cube3d
{
	int F;
	int C;
	t_textur *textur;
	int		Rx;
	int 	Ry;
	int 	n;
	int		s;
	int		e;
	int		w;
	char	*str;
	char	**map;
	int		len;
	int		i;
}			t_cube3d;

int	ft_cub(char *c, int i);
void	read_file(t_cube3d *cube,int fd);
void	ft_check_file(char *file, t_cube3d *cube);
void ft_start_parsing(t_cube3d *cube);
t_textur	*add_textur_to_list(t_textur *textur, char *content, int type);
void	ft_textur_list_add_back(t_textur **lst, t_textur *new);
t_textur	*ft_textur_lst_last(t_textur *lst);

#endif