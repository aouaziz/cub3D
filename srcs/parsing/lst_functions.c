/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:58:21 by aouaziz           #+#    #+#             */
/*   Updated: 2023/07/13 19:28:04 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3D.h"

t_cube3d	*add_textur_to_list(t_cube3d *cube, char *content, int type)
{
	t_textur	*new;

	new = malloc(sizeof(t_textur));
	if (!new)
		return (NULL);
	new->type = type;
	new->file = content;
	new->next = NULL;
	ft_textur_list_add_back(&cube->textur, new);
	cube->i = 1;
	return (cube);
}

void	ft_textur_list_add_back(t_textur **lst, t_textur *new)
{
	t_textur	*i;

	if (!new)
		return ;
	i = ft_textur_lst_last(*lst);
	if (!i)
		*lst = new;
	else
		i->next = new;
}
t_textur	*ft_textur_lst_last(t_textur *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
	{
		if (lst->next == 0)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}