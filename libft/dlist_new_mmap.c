/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 15:35:22 by pbourdon          #+#    #+#             */
/*   Updated: 2016/11/08 20:18:57 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist		*dlist_new_mmap(t_dlist *p_new, t_arena *arena, char *adress)
{
	ft_putstr("here \n");
	p_new = (t_dlist *)adress;
	if (arena->tiny == adress)
	{
		ft_putstr("on modifie l'adresse pour tiny\n");
		arena->tiny = adress + sizeof(p_new);
	}
	else if (arena->small == adress)
	{
		arena->small = adress + sizeof(p_new);
		ft_putstr("on modifie l'adresse pour small\n");
	}
	else if (arena->large == adress)
		arena->large = adress + sizeof(p_new);
	if (p_new != NULL)
	{
		p_new->p_head = NULL;
		p_new->p_tail = NULL;
	}
	return (p_new);
}
