/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 18:11:59 by pbourdon          #+#    #+#             */
/*   Updated: 2016/11/21 19:02:11 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*ft_mmap(size_t size)
{
	void	*pointer;

	pointer = mmap(0, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1,
			0);
	return (pointer);
}

void	*tiny(size_t size, t_master *master, void *pointer, t_node *p_temp)
{
	if ((p_temp = ft_check_malloc_from_free(master->tiny, size)) != NULL)
		return (ft_get_malloc_from_free(p_temp, size, master->tiny, master));
	else if (master->available_tiny_client >= size)
	{
		pointer = master->current_tiny_client;
		master->current_tiny_client += size + 1;
		master->available_tiny_client -= size - 1;
		master->temp_size = size;
		master->tiny = ft_check_adresses(master->tiny, pointer, master,
				master->page_tiny_client);
		return (pointer);
	}
	else
	{
		pointer = ft_mmap(40960);
		master->pages = ft_check(master->pages, pointer, master, 40960);
		master->page_tiny_client = pointer;
		master->current_tiny_client = pointer + size + 1;
		master->available_tiny_client = 40960 - size - 1;
		master->temp_size = size;
		master->tiny = ft_check_adresses(master->tiny, pointer, master,
				master->page_tiny_client);
		return (pointer);
	}
}

void	*small(size_t size, t_master *master, void *pointer, t_node *p_temp)
{
	if ((p_temp = ft_check_malloc_from_free(master->small, size)) != NULL)
		return (ft_get_malloc_from_free(p_temp, size, master->small, master));
	else if (master->available_small_client >= size)
	{
		pointer = master->current_small_client;
		master->current_small_client += size + 1;
		master->available_small_client -= size - 1;
		master->temp_size = size;
		master->small = ft_check_adresses(master->small, pointer, master,
				master->page_small_client);
		return (pointer);
	}
	else
	{
		pointer = ft_mmap(409600);
		master->pages = ft_check(master->pages, pointer, master, 409600);
		master->current_small_client = pointer + size + 1;
		master->page_small_client = pointer;
		master->available_small_client = 409600 - size - 1;
		master->temp_size = size;
		master->small = ft_check_adresses(master->small, pointer, master,
				master->page_small_client);
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
	void		*p_temp;

	if ((p_temp = ft_check_malloc_from_free(master->large, size)) != NULL)
		return (ft_get_malloc_from_free(p_temp, size, master->large, master));
	pointer = mmap(0, ft_get_page(size), PROT_READ | PROT_WRITE, MAP_ANON |
			MAP_PRIVATE, -1, 0);
	master->pages = ft_check(master->pages, pointer, master, size);
	master->page_large_client = pointer;
	master->temp_size = size;
	master->large = ft_check_adresses(master->large, pointer, master,
			master->page_large_client);
	return (pointer);
}
