/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 15:35:22 by pbourdon          #+#    #+#             */
/*   Updated: 2016/11/08 20:14:40 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_master		*dlist_new_master(t_master *p_master)
{

	t_dlist		*tiny;
	t_dlist		*small;
	t_dlist		*large;
	t_arena		*arena;

	large = NULL;
	tiny = NULL;
	small = NULL;
	arena = NULL;
	arena = get_adress(arena);
	large = dlist_new_mmap(large, arena, arena->large);
	tiny = dlist_new_mmap(tiny, arena, arena->tiny);
	small = dlist_new_mmap(small, arena, arena->small);
	p_master = malloc(sizeof(*p_master));
	if (p_master != NULL)
	{
		p_master->tiny = tiny;
		p_master->small = small;
		p_master->large = large;
		p_master->arena = arena;
	}
	return (p_master);
}
