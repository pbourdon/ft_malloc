/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_data_mmap_adresses2.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 18:24:22 by pbourdon          #+#    #+#             */
/*   Updated: 2016/11/21 19:29:09 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_dlist		*normed(t_dlist *list, t_node *p_new, t_node *p_temp)
{
	list->p_head = p_new;
	p_new->p_prev = NULL;
	p_new->p_next = p_temp;
	p_temp->p_prev = p_new;
	return (list);
}

t_dlist		*normed2(t_dlist *list, t_node *p_new, t_node *p_temp)
{
	if (p_temp->data >= p_new->data)
	{
		p_new->p_next = p_temp;
		p_new->p_prev = p_temp->p_prev;
		p_temp->p_prev->p_next = p_new;
		p_temp->p_prev = p_new;
		return (list);
	}
	else
		return (nik_the_norm3(list, p_new, 1));
}

t_dlist		*normed3(t_dlist *list, t_node *p_new, t_node *p_temp)
{
	p_new->p_prev = p_temp->p_prev;
	p_new->p_next = p_temp;
	p_temp->p_prev->p_next = p_new;
	p_temp->p_prev = p_new;
	return (list);
}

t_node		*normed4(t_node *p_new, void *linked_page, t_master *master)
{
	p_new->available_from_free = 0;
	p_new->linked_page = linked_page;
	p_new->size = master->temp_size;
	p_new->pos = master->current_pos + 1;
	return (p_new);
}
