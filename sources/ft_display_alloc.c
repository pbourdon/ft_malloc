/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_alloc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 18:14:02 by pbourdon          #+#    #+#             */
/*   Updated: 2016/11/22 12:48:25 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	ft_display(t_node *p_temp)
{
	char	*result;
	char	*base_digits;

	result = mmap(0, 4096, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1,
			0);
	base_digits = result + 100;
	ft_putstr(ft_itoa_base2((int)p_temp->data, 16, result, base_digits));
	if (p_temp->freed == 1)
		ft_putstr(" (This pointer is already freed)\n");
	else
	{
		ft_putstr(" - ");
		ft_putstr(ft_itoa_base2((int)p_temp->data + p_temp->size, 16, result, base_digits));
		ft_putstr(" : ");
		ft_putnbr((int)p_temp->size);
		ft_putstr(" octets\n");
	}

	munmap(result, 4096);
}
