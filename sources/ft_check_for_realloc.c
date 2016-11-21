/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_for_realloc.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 14:20:27 by pbourdon          #+#    #+#             */
/*   Updated: 2016/11/21 18:33:13 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	ft_check_for_realloc(t_node *current, t_node *p_new, void *page,
		void *adress)
{
	size_t		diff;
	t_node		*p_temp;

	diff = 11111111111;
	while (p_new)
	{
		if (p_new->freed == 0 && p_new->linked_page == page && adress >
			p_new->data && diff > (int)adress - (int)p_new->data &&
			((int)adress - (int)p_new->data) > 0)
		{
			diff = adress - p_new->data;
			p_temp = p_new;
		}
		p_new = p_new->p_next;
	}
	if (diff != 11111111111)
	{
		p_temp->available_from_free += current->size;
	}
}
