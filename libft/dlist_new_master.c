/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 15:35:22 by pbourdon          #+#    #+#             */
/*   Updated: 2016/11/12 17:53:27 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_master		*dlist_new_master(t_master *global)
{
	t_dlist		*tiny;
	t_dlist		*small;
	t_dlist		*large;
	t_dlist		*pages;

	large = NULL;
	tiny = NULL;
	small = NULL;
	pages = NULL;
	pages = dlist_new_mmap(pages);
	global = (t_master *)mmap(0, 4096, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	global->current = (void *)pages + sizeof(*global) + 1;
	global->available = 4096 - sizeof(*global) - 1;
	pages = ft_add_data_mmap(pages, pages, global);
	pages = ft_add_data_mmap(pages, global, global);
	large = dlist_new_mmap(large);
	pages = ft_add_data_mmap(pages, large, global);
	tiny = dlist_new_mmap(tiny);
	pages = ft_add_data_mmap(pages, tiny, global);
	small = dlist_new_mmap(small);
	pages = ft_add_data_mmap(pages, small, global);
	ft_display_list(pages);
	if (global != NULL)
	{
		global->tiny = tiny;
		global->small = small;
		global->large = large;
		global->pages = pages;
	}
	return (global);
}
