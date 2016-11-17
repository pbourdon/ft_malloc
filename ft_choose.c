/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:21:36 by pbourdon          #+#    #+#             */
/*   Updated: 2016/11/17 11:55:08 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*ft_choose(size_t size, t_master *master)
{
	if (size <= 409)
		return (tiny(size, master));
	else if (size <= 4096)
		return (small(size, master));
	else
		return (large(size, master));
	return (NULL);
}
