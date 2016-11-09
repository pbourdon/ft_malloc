/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_adress.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 18:30:14 by pbourdon          #+#    #+#             */
/*   Updated: 2016/11/09 19:11:51 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_arena		*get_adress(t_arena *arena)
{
	arena->tiny = mmap(0, 4096, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE,
-1, 0);
	arena->tiny_available = 4096;
	arena->small = mmap(0, 4096, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE,
-1, 0);
	arena->small_available = 4096;
	arena->large = mmap(0, 4096, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE,
-1, 0);
	arena->large_available = 4096;
	return (arena);
}
