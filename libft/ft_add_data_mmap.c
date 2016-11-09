/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 18:46:12 by pbourdon          #+#    #+#             */
/*   Updated: 2016/11/09 19:04:43 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node		*malloc_mmap(int choice, t_node *p_new, t_arena *arena)
{
	if (choice == 0) // it's tiny, you use tiny's adress already created by get_adress
	{
		p_new = (t_node *)arena->tiny;
		ft_putnbr((int)arena->tiny);
		arena->tiny += sizeof(p_new);
		arena->tiny_available -= sizeof(p_new); // we reduce the available size of memory availableble for tiny
		ft_putstr(" the new available free space for tiny is : ");
		ft_putnbr(arena->tiny_available);
		ft_putchar('\n');
	}
	return (p_new);
}

t_dlist		*dlist_prepend_mmap(t_dlist *p_list, int data, int choice, t_arena *arena)
{
	t_node		*p_new;

	if (p_list != NULL)
	{
		p_new = malloc_mmap(choice, p_new, arena);
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

t_dlist		*dlist_append_mmap(t_dlist *p_list, int data, int choice, t_arena *arena)
{
	t_node		*p_new;

	if (p_list != NULL)
	{
		p_new = malloc_mmap(choice, p_new, arena);
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

t_dlist		*ft_add_data_mmap(t_dlist *p_list, int data, int choice, t_arena *arena)
{
	if (p_list != NULL)
		p_list = dlist_append_mmap(p_list, data, choice, arena);
	return (p_list);
}
