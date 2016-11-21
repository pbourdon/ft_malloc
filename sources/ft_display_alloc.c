/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_alloc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 18:14:02 by pbourdon          #+#    #+#             */
/*   Updated: 2016/11/21 18:15:17 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	ft_display(void *data, size_t size, int pos)
{
	ft_itoa_base2((int)data, 16);
	ft_putstr(" - ");
	ft_itoa_base2((int)data + size, 16);
	ft_putstr(" : ");
	ft_putnbr((int)size);
	ft_putstr(" octets\n");
}
