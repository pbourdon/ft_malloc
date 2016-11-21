/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_malloc_from_free.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 17:20:52 by pbourdon          #+#    #+#             */
/*   Updated: 2016/11/21 18:33:49 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_node		*ft_check_malloc_from_free(t_dlist *list, size_t size)
{
	t_node	*p_temp;

	p_temp = list->p_head;
	while (p_temp)
	{
		if (p_temp->freed == 1 && p_temp->size >= size)
			return (p_temp);
		p_temp = p_temp->p_next;
	}
	return (0);
}

void		*ft_get_malloc_from_free(t_node *p_temp, size_t size, t_dlist *list,
			t_master *master)
{
	void	*pointer;

	pointer = p_temp->data;
	master->temp_size = p_temp->size - size - 1;
	p_temp->size = size;
	p_temp->freed = 0;
	master->temp_freed = 1;
	list = ft_check_adresses(list, pointer + size + 1, master,
			p_temp->linked_page);
	return (pointer);
}
