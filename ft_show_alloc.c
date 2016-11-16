/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_alloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 19:13:00 by pbourdon          #+#    #+#             */
/*   Updated: 2016/11/16 18:05:04 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"


void		ft_display(void *data, size_t size)
{
	ft_putstr(ft_itoa_base((int)data, 16));
	ft_putstr(" - ");
	ft_putstr(ft_itoa_base((int)data + size, 16));
	ft_putstr(" : ");
	ft_putnbr((int)size);
	ft_putstr(" octets\n");
}

void		ft_display_special_list(t_dlist *list)
{
	t_node	*p_temp;

	p_temp = list->p_head;
	if (list != NULL && p_temp != NULL)
	{
		while (p_temp != NULL && p_temp->freed == 1)
			p_temp = p_temp->p_next;
		ft_putstr(ft_itoa_base((int)p_temp->data, 16));
		ft_putstr("\n");
		while (p_temp != NULL)
		{
			if (p_temp->freed != 1)
				ft_display(p_temp->data, p_temp->size);
			p_temp = p_temp->p_next;
		}
	}
	else
		ft_putstr("NULL\nNULL - NULL : 0 octet\n");
}

t_dlist		*ft_sort_by_num(t_dlist *list)
{
	t_node		*p_temp;
	int			temp;
	size_t		max;

	p_temp = list->p_head;
	if (list != NULL && p_temp != NULL)
	{
		max = (size_t)p_temp->data;
		while (p_temp)
		{
			if (max < (size_t)p_temp->data)
			{
			}
		}
	}
	return (list);
}

size_t		ft_get_total_tiny(t_master *master)
{
	t_node	*p_temp;
	size_t	total;

	total = 0;
	p_temp = master->tiny->p_head;
	if (master->tiny != NULL && p_temp != NULL)
	{
		while (p_temp != NULL)
		{
			total += p_temp->size;
			p_temp = p_temp->p_next;
		}
	}
	return (total);
}

size_t		ft_get_total_small(t_master *master)
{
	t_node	*p_temp;
	size_t	total;

	total = 0;
	p_temp = master->small->p_head;
	if (master->tiny != NULL && p_temp != NULL)
	{
		while (p_temp != NULL)
		{
			total += p_temp->size;
			p_temp = p_temp->p_next;
		}
	}
	return (total);
}

size_t		ft_get_total_large(t_master *master)
{
	t_node	*p_temp;
	size_t	total;

	total = 0;
	p_temp = master->large->p_head;
	if (master->tiny != NULL && p_temp != NULL)
	{
		while (p_temp != NULL)
		{
			total += p_temp->size;
			p_temp = p_temp->p_next;
		}
	}
	return (total);
}




void		ft_show_alloc(t_master *master)
{
	ft_putstr("TINY : ");
	ft_display_special_list(master->tiny);
	ft_putstr("SMALL : ");
	ft_display_special_list(master->small);
	ft_putstr("LARGE : ");
	ft_display_special_list(master->large);
	ft_putstr("TOTAL : ");
	ft_putnbr(ft_get_total_tiny(master) + ft_get_total_small(master) +
			ft_get_total_large(master));
	ft_putstr(" octets\n");
}
