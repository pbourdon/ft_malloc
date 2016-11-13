/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:21:36 by pbourdon          #+#    #+#             */
/*   Updated: 2016/11/13 17:20:05 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*ft_choose(size_t size, t_master *master)
{
	if (size <= 409)
	{
		return (tiny(size, master));
	}
/*	else if (size <= 4096)
	{
		small(size, master);
	}
	else
	{
		large(size, master);
	}
	*/
	return (NULL);
}
