/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 18:46:12 by pbourdon          #+#    #+#             */
/*   Updated: 2016/11/12 17:53:47 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist		*dlist_prepend_mmap(t_dlist *p_list, void *data, t_master *global)
{
	t_node		*p_new;

	if (p_list != NULL)
	{
	//	p_new = malloc_mmap(choice, p_new, arena);
		if (p_new != NULL)
		{
			p_new->data = data;
			p_new->p_prev = NULL;
			if (p_list->p_tail == NULL)
				p_list = nik_the_norm2(p_list, p_new, 0);
			else
				p_list = nik_the_norm2(p_list, p_new, 1);
		}
	}
	return (p_list);
}

t_dlist		*dlist_append_mmap(t_dlist *p_list, void *data, t_master *global)
{
	t_node		*p_new;

	if (p_list != NULL)
	{
		p_new = (t_node *)(global->current);
		global->current += sizeof(*p_new) + 1;
		global->available -= sizeof(*p_new) - 1;
		if (p_new != NULL)
		{
			p_new->data = data;
			p_new->p_next = NULL;
			if (p_list->p_tail == NULL)
				p_list = nik_the_norm3(p_list, p_new, 0);
			else
				p_list = nik_the_norm3(p_list, p_new, 1);
		}
	}
	return (p_list);
}

t_dlist		*ft_add_data_mmap(t_dlist *p_list, void *data, t_master *global)
{
	if (p_list != NULL)
		p_list = dlist_append_mmap(p_list, data, global);
	return (p_list);
}
