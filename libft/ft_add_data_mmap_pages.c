/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 18:46:12 by pbourdon          #+#    #+#             */
/*   Updated: 2016/11/12 18:16:09 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist		*dlist_append_mmap_pages(t_dlist *p_list, void *data, t_master *global)
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

t_dlist		*ft_add_data_mmap_pages(t_dlist *p_list, void *data, t_master *global)
{
	if (p_list != NULL)
		p_list = dlist_append_mmap_pages(p_list, data, global);
	return (p_list);
}
