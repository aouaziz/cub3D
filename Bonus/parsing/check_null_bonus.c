/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_null_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 11:18:02 by aouaziz           #+#    #+#             */
/*   Updated: 2023/07/31 14:01:46 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"


void	check_Zero_Door_Surroundings_bonus(char **map)
{
	int	i;
	int	j;
	int	p;

	i = 0;
	p = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0')
				validate_Zero_Position_bonus(map, i, j);
			else if(map[i][j] == 'D')
				validate_Door_Position_bonus(map, i, j);
			j++;
		}
		i++;
	}
}
void	validate_Door_Position_bonus(char **map, int i, int j)
{
	if (map[i + 1][j] == '\0' || map[i + 1][j] == '\n' || map[i + 1][j] == ' ')
		ft_print_error("Invalid Map - Incorrect Door Position\n");
	else if (map[i - 1][j] == '\0' || map[i - 1][j] == '\n' || map[i
			- 1][j] == ' ')
		ft_print_error("Invalid Map - Incorrect Door Position\n");
	else if (map[i][j + 1] == '\0' || map[i][j + 1] == '\n' || map[i][j
			+ 1] == ' ')
		ft_print_error("Invalid Map - Incorrect Door Position\n");
	else if (map[i][j - 1] == '\0' || map[i][j - 1] == '\n' || map[i][j
			- 1] == ' ')
		ft_print_error("Invalid Map - Incorrect Door Position\n");
}
void	validate_Zero_Position_bonus(char **map, int i, int j)
{
	if (map[i + 1][j] == '\0' || map[i + 1][j] == '\n' || map[i + 1][j] == ' ')
		ft_print_error("Invalid Map - Incorrect '0' Position\n");
	else if (map[i - 1][j] == '\0' || map[i - 1][j] == '\n' || map[i
			- 1][j] == ' ')
		ft_print_error("Invalid Map - Incorrect '0' Position\n");
	else if (map[i][j + 1] == '\0' || map[i][j + 1] == '\n' || map[i][j
			+ 1] == ' ')
		ft_print_error("Invalid Map - Incorrect '0' Position\n");
	else if (map[i][j - 1] == '\0' || map[i][j - 1] == '\n' || map[i][j
			- 1] == ' ')
		ft_print_error("Invalid Map - Incorrect '0' Position\n");
}
void	check_First_last_Line_bonus(char *line)
{
	int	len;

	len = ft_strlen(line) - 1;
	if (line[len] == '\n')
		len--;
	while (len > 0 && line[len] == ' ')
		len--;
	if (line[0] != '1' || line[len] != '1')
		ft_print_error("Invalid Map - Map Not Closed\n");
	free(line);
}