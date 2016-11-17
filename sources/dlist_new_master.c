/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 15:35:22 by pbourdon          #+#    #+#             */
/*   Updated: 2016/11/17 11:58:11 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"


t_master		*ft_init_master(t_master *master)
{
	master = (t_master *)mmap(0, 4096, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	if (master == NULL)
		return (NULL);
	master->available_struct = 0;
	master->current_struct = 0;
	master->current_small_client = 0;
	master->current_tiny_client = 0;
	master->available_tiny_client = 0;
	master->available_small_client = 0;
	return (master);
}

t_master		*dlist_new_master(t_master *master)
{
	t_dlist		*tiny;
	t_dlist		*small;
	t_dlist		*large;
	t_dlist		*pages;

	large = NULL;
	tiny = NULL;
	small = NULL;
	pages = NULL;
	master = ft_init_master(master);
	if (master == NULL)
		return (NULL);
	master->current = (void *)master + sizeof(*master) + 1;
	master->available = 4096 - sizeof(*master) - 1;
	pages = dlist_new_mmap(pages, master);
	pages = ft_check(pages, master, master, 4096);
	large = dlist_new_mmap(large, master);
	tiny = dlist_new_mmap(tiny, master);
	small = dlist_new_mmap(small, master);
	master->tiny = tiny;
	master->small = small;
	master->large = large;
	master->pages = pages;
	master->current_pos = 0;
	return (master);
}
