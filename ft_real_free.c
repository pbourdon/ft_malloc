/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_real_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 11:55:54 by pbourdon          #+#    #+#             */
/*   Updated: 2016/11/16 17:24:53 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int		ft_check_and_delete(int munmap, t_node *p_new, t_master *master)
{
	if (munmap == 0)
	{
		if (p_new->p_prev != NULL)
			p_new->p_prev->p_next = p_new->p_next;
		else
			master->pages->p_head = p_new->p_next;
		if (p_new->p_next != NULL)
			p_new->p_next->p_prev = p_new->p_prev;
		else
			master->pages->p_tail = p_new->p_prev;
	}
	return (0);
}

int		ft_munmap(t_master *master, t_node *p_new, void *page)
{
	int		go;

	go = 1;
	while (p_new)
	{
		if (p_new->linked_page == page && p_new->freed == 0)
		{
			return (1);
			go = 0;
		}
		p_new = p_new->p_next;
	}
	p_new = master->pages->p_head;
	while (p_new)
	{
		if (p_new->data == page)
			return (ft_check_and_delete(munmap(page, p_new->size), p_new, master));
		p_new = p_new->p_next;
	}
	return (0);
}

int		ft_real_free_large(void *pointer, t_master *master)
{
	t_node *p_new;

	p_new = master->large->p_head;
	while (p_new)
	{
		if (p_new->data == pointer)
		{
			p_new->freed = 1;
			ft_check_for_realloc(p_new, master->large->p_head, p_new->linked_page, p_new->data);
			return (ft_munmap(master, master->large->p_head, p_new->linked_page));
		}
		p_new = p_new->p_next;
	}
	return (0);
}

int		ft_real_free_small(void *pointer, t_master *master)
{
	t_node *p_new;

	p_new = master->small->p_head;
	while (p_new)
	{
		if (p_new->data == pointer)
		{
			p_new->freed = 1;
			ft_check_for_realloc(p_new, master->small->p_head, p_new->linked_page, p_new->data);
			return (ft_munmap(master, master->small->p_head, p_new->linked_page));
		}
		p_new = p_new->p_next;
	}
	return (ft_real_free_large(pointer, master));
}

int		ft_real_free_tiny(void *pointer, t_master *master)
{
	t_node *p_new;

	p_new = master->tiny->p_head;
	while (p_new)
	{
		if (p_new->data == pointer)
		{
			p_new->freed = 1;
			ft_check_for_realloc(p_new, master->tiny->p_head, p_new->linked_page, p_new->data);
			return (ft_munmap(master, master->tiny->p_head, p_new->linked_page));
		}
		p_new = p_new->p_next;
	}
	return (ft_real_free_small(pointer, master));
}
