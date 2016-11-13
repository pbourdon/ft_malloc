/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 18:11:59 by pbourdon          #+#    #+#             */
/*   Updated: 2016/11/13 18:02:04 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*tiny(size_t size, t_master *master)
{
	void		*pointor;

	if (master->available_tiny_client >= size)
	{
		pointor = master->current_tiny_client;
		master->current_tiny_client += size + 1;
		master->available_tiny_client -= size - 1;
		master->tiny = ft_check_adresses(master->tiny, pointor, master);
		return (pointor);
	}
	else
	{
		pointor = mmap(0, 4096, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
		master->pages = ft_check(master->pages, pointor, master);
		master->current_tiny_client = pointor + size + 1;
		master->available_tiny_client = 4096 - size - 1;
		master->tiny = ft_check_adresses(master->tiny, pointor, master);
		// need to add the adress given to struct tiny;
		return (pointor);
	}
}
