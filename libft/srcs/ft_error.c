/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 06:10:40 by aouaziz           #+#    #+#             */
/*   Updated: 2023/07/11 06:12:22 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_print_error(int e)
{
	if(e == 1)
		printf("\033[91m%s", "something wrong with the path (ㆆ_ㆆ)!!!");
	else if(e == 2)
		printf("\033[91m%s", "something wrong with map (⌐■_■)!!!");
	exit(1);
}
