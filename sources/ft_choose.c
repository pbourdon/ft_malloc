/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:21:36 by pbourdon          #+#    #+#             */
/*   Updated: 2016/11/21 18:10:33 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*ft_choose(size_t size, t_master *master)
{
	if (size <= 409)
		return (tiny(size, master, NULL, NULL));
	else if (size <= 4096)
		return (small(size, master, NULL, NULL));
	else
		return (large(size, master));
	return (NULL);
}
