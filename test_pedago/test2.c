/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 18:37:04 by pbourdon          #+#    #+#             */
/*   Updated: 2016/11/19 18:47:32 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>


int		main(void)
{
	int		index;
	char	*str;

	index = 0;
	str = malloc(10);
	printf ("%p\n", str);
	free (str);
	str = malloc(5);
	printf ("%p\n", str);
	// does the malloc allows to re-malloc at the same adress which had already been freed ?
	// the 2 prints have to be the same
//	show_alloc_mem();
	return (0);
}
