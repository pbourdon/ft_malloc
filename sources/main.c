/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 18:12:46 by pbourdon          #+#    #+#             */
/*   Updated: 2016/11/22 13:09:54 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_master	*g_master;

void	*malloc(size_t size)
{
	void		*pointer;

	if (g_master == NULL)
		g_master = dlist_new_master(g_master);
	if (g_master == NULL)
		return (NULL);
	ft_putstr(" malloc of size : ");
	ft_putnbr(size);
	ft_putchar(':');
	pointer = ft_choose(size, g_master);
	if (pointer == NULL)
		ft_putstr(" NULL");
	ft_putstr("\n");
	return (pointer);
}

void	free(void *ptr)
{
	if (ptr != NULL)
		ft_real_free_tiny(ptr, g_master);
}

void	show_alloc_mem(void)
{
	ft_show_alloc(g_master);
}

void	*realloc(void *ptr, size_t size)
{
//	ft_putstr(" trying to realloc \n");
	if (ptr != NULL && size > 0)
		return (ft_check_and_realloc(ptr, size, g_master));
	else if (ptr != NULL && size <= 0)
		free(ptr);
	else if (ptr == NULL && size > 0)
		return (malloc(size));
	return (NULL);
}
