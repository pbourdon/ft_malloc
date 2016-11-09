/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 15:35:22 by pbourdon          #+#    #+#             */
/*   Updated: 2016/11/09 19:13:13 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_master		*dlist_new_master(t_master *global)
{
	t_dlist		*tiny;
	t_dlist		*small;
	t_dlist		*large;
	t_arena		*arena;

	large = NULL;
	tiny = NULL;
	small = NULL;
	arena = NULL;
	arena = mmap(0, 4096, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	arena = get_adress(arena);
	large = dlist_new_mmap(large, arena, arena->large);
	tiny = dlist_new_mmap(tiny, arena, arena->tiny);
	small = dlist_new_mmap(small, arena, arena->small);
	global = mmap(0, 4096, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	if (global != NULL)
	{
		global->tiny = tiny;
		global->small = small;
		global->large = large;
		global->arena = arena;
	}
	tiny = ft_add_data_mmap(tiny, 10, 0, arena);

	ft_display_list(tiny);
	return (global);
}
