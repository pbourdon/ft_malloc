/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 18:11:59 by pbourdon          #+#    #+#             */
/*   Updated: 2016/11/13 19:12:53 by pbourdon         ###   ########.fr       */
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
		master->tiny = ft_check_adresses(master->tiny, pointor, master, size);
		return (pointor);
	}
	else
	{
		pointor = mmap(0, 4096, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
		master->pages = ft_check(master->pages, pointor, master);
		master->current_tiny_client = pointor + size + 1;
		master->available_tiny_client = 4096 - size - 1;
		master->tiny = ft_check_adresses(master->tiny, pointor, master, size);
		return (pointor);
	}
}

void	*small(size_t size, t_master *master)
{
	void		*pointor;

	if (master->available_tiny_client >= size)
	{
		pointor = master->current_small_client;
		master->current_small_client += size + 1;
		master->available_small_client -= size - 1;
		master->small = ft_check_adresses(master->small, pointor, master, size);
		return (pointor);
	}
	else
	{
		pointor = mmap(0, 40960, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
		master->pages = ft_check(master->pages, pointor, master);
		master->current_small_client = pointor + size + 1;
		master->available_small_client = 40960 - size - 1;
		master->small = ft_check_adresses(master->small, pointor, master, size);
		return (pointor);
	}
}

void	*large(size_t size, t_master *master)
{
	void		*pointor;

	pointor = mmap(0, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	master->pages = ft_check(master->pages, pointor, master);
	master->large = ft_check_adresses(master->large, pointor, master, size);
	return (pointor);
}
