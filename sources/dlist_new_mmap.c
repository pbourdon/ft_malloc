/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 15:35:22 by pbourdon          #+#    #+#             */
/*   Updated: 2016/11/21 18:06:20 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_dlist		*dlist_new_mmap(t_dlist *p_new, t_master *master)
{
	int		right;

	right = 0;
	if (master->available_struct >= sizeof(*p_new))
	{
		p_new = (t_dlist *)master->current_struct;
		master->current_struct += sizeof(*p_new) + 1;
		master->available_struct -= sizeof(*p_new) - 1;
	}
	else
	{
		p_new = (t_dlist *)mmap(0, 4096, PROT_READ | PROT_WRITE, MAP_ANON |
				MAP_PRIVATE, -1, 0);
		master->current_struct = (void *)p_new + sizeof(*p_new);
		master->available_struct = 4096 - sizeof(*p_new) - 1;
		right = 1;
	}
	if (p_new != NULL)
	{
		p_new->p_head = NULL;
		p_new->p_tail = NULL;
	}
	if (right == 1)
		p_new = ft_check(p_new, p_new, master, 4096);
	return (p_new);
}
