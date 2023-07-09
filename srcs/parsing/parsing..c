/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing..c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 06:58:32 by aouaziz           #+#    #+#             */
/*   Updated: 2023/07/08 06:58:51 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3D.h"

void	ft_print_error(int e)
{
	if(e == 1)
		ft_printf("\033[91m%s", "something wrong with the path (ㆆ_ㆆ)!!!");
	else if(e == 2)
		ft_printf("\033[91m%s", "something wrong with map (⌐■_■)!!!");
	exit(1);
}
int	ft_cub(char *c, int i)
{
	if (c[i - 1] == 'b' && c[i - 2] == 'u' && c[i - 3] == 'c'
		&& c[i - 4] == '.')
		return (1);
	else
		return (0);
}