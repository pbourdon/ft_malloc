/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 15:13:06 by pbourdon          #+#    #+#             */
/*   Updated: 2016/11/16 15:08:03 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_display_list(t_dlist *p_list)
{
	t_node		*p_temp;

	p_temp = p_list->p_head;
	if (p_list != NULL)
	{
		while (p_temp != NULL)
		{
			ft_putnbr((int)p_temp->data);
			ft_putstr(" of size : ");
			ft_putnbr(p_temp->size);
			ft_putstr(" and has extra space of : ");
			ft_putnbr(p_temp->available_from_free);
			ft_putchar('\n');
			p_temp = p_temp->p_next;
		}
	}
	return (0);
}
