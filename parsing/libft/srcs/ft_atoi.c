/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 04:29:22 by aouaziz           #+#    #+#             */
/*   Updated: 2023/08/06 03:52:36 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_checkspace(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		s;
	size_t	r;

	i = ft_checkspace(str);
	r = 0;
	s = 1;
	if (!str)
		return (0);
	if (str[i] == '-')
		s *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = (r * 10) + (str[i] - '0');
		i++;
	}
	if (r > __LONG_LONG_MAX__ && s == 1)
		return (-1);
	if (r > __LONG_LONG_MAX__ && s == -1)
		return (0);
	return (r * s);
}

int	ft_color_resolution(char *str)
{
	int		i;
	size_t	r;
	char	**tab;
	char	*line;

	i = 0;
	r = 0;
	if (!str)
		ft_print_error("Invalid Color Parameter\n");
	line = ft_strtrim(str, " ");
	ft_checkerror(line, 1);
	tab = ft_split(line, ',');
	while (tab[i])
		i++;
	if (i != 3 || tab[2][0] == '\n')
		ft_print_error("Invalid Color Parameter\n");
	r = (ft_atoi_color(tab[0]) * 65536) + (ft_atoi_color(tab[1]) * 256)
		+ ft_atoi_color(tab[2]);
	free(line);
	free_double_str(tab);
	return (r);
}

void	ft_checkerror(char *str, int j)
{
	int	i;

	i = 0;
	if (j == 1)
	{
		j = 0;
		while (str[i])
		{
			if (str[i] == ',')
				j++;
			i++;
		}
		if (j != 2)
			ft_print_error("Invalid Color Parameter\n");
		return ;
	}
	while (str[i] == ' ' || str[i] == '+')
		i++;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9'))
			i++;
		else
			ft_print_error("Invalid Color Parameter\n");
	}
}

int	ft_atoi_color(char *str)
{
	int		i;
	size_t	r;

	i = 0;
	r = 0;
	ft_checkerror(str, 0);
	while (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = (r * 10) + (str[i] - '0');
		i++;
	}
	if (r > __LONG_LONG_MAX__ || r > 255)
		ft_print_error("Color Value Out of Range 0 -> 255\n");
	return (r);
}
