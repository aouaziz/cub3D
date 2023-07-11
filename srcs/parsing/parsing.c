/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 06:58:32 by aouaziz           #+#    #+#             */
/*   Updated: 2023/07/11 06:11:58 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3D.h"


int	ft_cub(char *c, int i)
{
	if (c[i - 1] == 'b' && c[i - 2] == 'u' && c[i - 3] == 'c'
		&& c[i - 4] == '.')
		return (1);
	else
		return (0);
}
static void print_str(char **str)
{
    int i;

    // Iterate through the array and print each string
    for (i = 0; str[i] != NULL; i++)
    {
        printf("%s\n", str[i]);
    }
}
void ft_start_parsing(t_cube3d *cube)
{
	print_str(cube->map);
	return ;
}