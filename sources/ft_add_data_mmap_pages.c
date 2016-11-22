/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 18:46:12 by pbourdon          #+#    #+#             */
/*   Updated: 2016/11/21 19:46:31 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_node		*create_node(t_node *p_new, t_master *master)
{
	if (master->available >= sizeof(*p_new))
	{
		p_new = (t_node *)(master->current);
		master->current += sizeof(*p_new) + 1;
		master->available -= sizeof(*p_new) - 1;
	}
	else
		return (NULL);
	return (p_new);
}

t_dlist		*dlist_append_mmap_pages(t_dlist *p_list, void *data,
				t_master *master, size_t size)
{
	t_node		*p_new;

	p_new = NULL;
	if (p_list != NULL)
	{
		p_new = create_node(p_new, master);
		if (p_new != NULL)
		{
			p_new->data = data;
			p_new->size = size;
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

t_dlist		*ft_add_data_mmap_pages(t_dlist *p_list, void *data,
				t_master *master, size_t size)
{
	if (p_list != NULL)
		p_list = dlist_append_mmap_pages(p_list, data, master, size);
	return (p_list);
}

/*
** ft_check is the same function than ft_check_adresses include
** ft_add_data_mmap_adresses but for the pages struct.
*/

t_dlist		*ft_check(t_dlist *p_list, void *data, t_master *master,
				size_t size)
{
	t_node		*p_new;

	p_new = NULL;
	if (master->available <= sizeof(*p_new) * 2)
	{
		p_new = (t_node *)mmap(0, 4096, PROT_READ | PROT_WRITE, MAP_ANON |
				MAP_PRIVATE, -1, 0);
		if (p_new != NULL)
		{
			master->current = (void *)p_new;
			master->available = 4096;
			p_list = ft_add_data_mmap_pages(p_list, p_new, master, 4096);
		}
	}
	return (ft_add_data_mmap_pages(p_list, data, master, size));
}
