/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_adress.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 18:30:14 by pbourdon          #+#    #+#             */
/*   Updated: 2016/11/08 20:18:20 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_arena		*get_adress(t_arena *arena)
{
	char	*str;

	ft_putstr(" here ");
	str = (char *)mmap(0, 4096, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE,
-1, 0);
	arena->tiny = str;
	str = (char *)mmap(0, 4096, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE,
-1, 0);
	arena->small = str;
	str = (char *)mmap(0, 4096, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE,
-1, 0);
	arena->large = str;
	return (arena);
}
