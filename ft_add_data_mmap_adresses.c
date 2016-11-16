/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 18:46:12 by pbourdon          #+#    #+#             */
/*   Updated: 2016/11/16 15:04:20 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_node		*sodo_cookies2(t_node *p_new, t_master *master)
{
	if (master->available_struct >= sizeof(*p_new))
	{
		p_new = (t_node *)(master->current);
		master->current += sizeof(*p_new) + 1;
		master->available -= sizeof(*p_new) - 1;
	}
	else
		return (NULL);
	return (p_new);
}

t_dlist		*dlist_append_mmap_adresses(t_dlist *p_list, void *data, t_master *master, void *linked_page)
{
	t_node		*p_new;

	p_new = NULL;
	if (p_list != NULL)
	{
		p_new = sodo_cookies2(p_new, master);
		if (p_new != NULL)
		{
			p_new->data = data;
			p_new->freed = 0;
			p_new->available_from_free = 0;
			p_new->linked_page = linked_page;
			p_new->size = master->temp_size;
			p_new->p_next = NULL;
			if (p_list->p_tail == NULL)
				p_list = nik_the_norm3(p_list, p_new, 0);
			else
				p_list = nik_the_norm3(p_list, p_new, 1);
		}
		else
			return (NULL);
	}
	return (p_list);
}

t_dlist		*ft_add_data_mmap_adresses(t_dlist *p_list, void *data, t_master *master, void *linked_page)
{
	if (p_list != NULL)
		p_list = dlist_append_mmap_adresses(p_list, data, master, linked_page);
	return (p_list);
}

t_dlist		*ft_check_adresses(t_dlist *p_list, void *data, t_master *master, void *linked_page)
{
	t_node		*p_new;

	p_new = NULL;
	if (master->available_struct < sizeof(*p_new))
	{
		p_new = (t_node *)mmap(0, 4096, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
		if (p_new != NULL)
		{
			master->current_struct = (void *)p_new;
			master->available_struct = 4096;
			master->pages = ft_add_data_mmap_pages(master->pages, p_new, master, 4096);
		}
	}
	return (ft_add_data_mmap_adresses(p_list, data, master, linked_page));
}
