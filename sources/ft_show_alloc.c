/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_alloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 19:13:00 by pbourdon          #+#    #+#             */
/*   Updated: 2016/11/22 12:48:39 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		ft_display_special_list(t_dlist *list)
{
	t_node	*p_temp;
	char	*string;
	char	*str2;

	string = mmap(0, 4096, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE,
			-1, 0);
	str2 = string + 100;
	p_temp = list->p_head;
	if (list != NULL && p_temp != NULL)
	{
		while (p_temp != NULL && p_temp->freed == 1)
			p_temp = p_temp->p_next;
		ft_putstr(ft_itoa_base2((int)p_temp->data, 16, string, str2));
		ft_putstr("\n");
		while (p_temp != NULL)
		{
			ft_display(p_temp);
			p_temp = p_temp->p_next;
		}
	}
	else
		ft_putstr("NULL\nNULL - NULL : 0 octet\n");
	munmap(string, 4096);
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
