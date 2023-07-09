/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:56:38 by aouaziz           #+#    #+#             */
/*   Updated: 2023/07/08 09:03:08 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "../libft/includes/libft.h"
# include <mlx.h>
typedef struct file
{
	int 	fd;
	int	    n_fd;
	int	    s_fd;
	int	    w_fd;
	int	    e_fd;	
}			t_file;
typedef struct cube3d
{
	t_file	*file;
	t_list	*f;
	t_list	*c;
	int 	n;
	int		s;
	int		e;
	int		w;
	char	*str;
	char	**map;
	int		len;
	int		i;
}			t_cube3d;

void	ft_print_error(int e);
int	ft_cub(char *c, int i);

#endif