/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_small_pos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 17:32:31 by pbourdon          #+#    #+#             */
/*   Updated: 2016/11/21 17:54:00 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int		ft_get_small_pos(t_dlist *list)
{
	t_node	*p_temp;
	int		small;

	small = 1;
	if (p_temp)
	{
		p_temp = list->p_head;
		small = p_temp->pos;
		while (p_temp)
		{
			if (p_temp->pos < small)
				small = p_temp->pos;
			p_temp = p_temp->p_next;
		}
	}
	return (small);
}

int		ft_get_max_pos(t_dlist *list)
{
	t_node	*p_temp;
	int		max;

	max = 0;
	if (p_temp)
	{
		p_temp = list->p_head;
		max = p_temp->pos;
		while (p_temp)
		{
			if (p_temp->pos > max)
				max = p_temp->pos;
			p_temp = p_temp->p_next;
		}
	}
	return (max);
}
