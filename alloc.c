/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 18:11:59 by pbourdon          #+#    #+#             */
/*   Updated: 2016/11/16 15:02:44 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*tiny(size_t size, t_master *master)
{
	void		*pointer;

	if (master->available_tiny_client >= size)
	{
		pointer = master->current_tiny_client;
		master->current_tiny_client += size + 1;
		master->available_tiny_client -= size - 1;
		master->temp_size = size;
		master->tiny = ft_check_adresses(master->tiny, pointer, master, master->page_tiny_client);
		return (pointer);
	}
	else
	{
		pointer = mmap(0, 40960, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
		master->pages = ft_check(master->pages, pointer, master, 40960);
		master->page_tiny_client = pointer;
		master->current_tiny_client = pointer + size + 1;
		master->available_tiny_client = 40960 - size - 1;
		master->temp_size = size;
		master->tiny = ft_check_adresses(master->tiny, pointer, master, master->page_tiny_client);
		return (pointer);
	}
}

void	*small(size_t size, t_master *master)
{
	void		*pointer;

	if (master->available_small_client >= size)
	{
		pointer = master->current_small_client;
		master->current_small_client += size + 1;
		master->available_small_client -= size - 1;
		master->temp_size = size;
		master->small = ft_check_adresses(master->small, pointer, master, master->page_small_client);
		return (pointer);
	}
	else
	{
		pointer = mmap(0, 409600, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
		master->pages = ft_check(master->pages, pointer, master, 409600);
		master->current_small_client = pointer + size + 1;
		master->page_small_client = pointer;
		master->available_small_client = 409600 - size - 1;
		master->temp_size = size;
		master->small = ft_check_adresses(master->small, pointer, master, master->page_small_client);
		return (pointer);
	}
}

size_t	ft_get_page(size_t size)
{
	size_t		page;

	page = 4096;
	while (page <= size)
		page += 4096;
	return (page);
}

void	*large(size_t size, t_master *master)
{
	void		*pointer;

	pointer = mmap(0, ft_get_page(size), PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	master->pages = ft_check(master->pages, pointer, master, size);
	master->page_large_client = pointer;
	master->temp_size = size;
	master->large = ft_check_adresses(master->large, pointer, master, master->page_large_client);
	return (pointer);
}
