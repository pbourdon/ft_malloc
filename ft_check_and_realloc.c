/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_and_realloc.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 15:08:11 by pbourdon          #+#    #+#             */
/*   Updated: 2016/11/16 15:40:42 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_node	*ft_find_ptr(t_master *master, t_node *p_new, void *ptr)
{
	p_new = master->tiny->p_head;
	while (p_new)
	{
		if (p_new->data == ptr)
			return (p_new);
		p_new = p_new->p_next;
	}
	p_new = master->small->p_head;
	while (p_new)
	{
		if (p_new->data == ptr)
			return (p_new);
		p_new = p_new->p_next;
	}
	p_new = master->large->p_head;
	while (p_new)
	{
		if (p_new->data == ptr)
			return (p_new);
		p_new = p_new->p_next;
	}
	return (NULL);
}

void	*ft_check_and_realloc(void *ptr, size_t size, t_master *master)
{
	t_node		*p_new;
	void		*temp_ptr;

	p_new = ft_find_ptr(master, p_new, ptr);
	if (p_new == NULL)
		return (NULL);
	if (p_new->available_from_free + p_new->size >= size)
	{
		p_new->available_from_free = 0;
		p_new->size = size;
		return (p_new->data);
	}
	else
	{
		temp_ptr = ft_malloc(size);
		ft_memcpy(temp_ptr, ptr, size);
		ft_free(ptr);
		return (temp_ptr);
	}
	return (NULL);
}
