/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_realloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 12:49:20 by pbourdon          #+#    #+#             */
/*   Updated: 2016/11/22 12:54:59 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		main(void)
{
	char	*string;
	int		index;

	string = malloc(10);
	printf ("%p : ", string);
	while (index < 10)
	{
		string[index] = 'A';
		index++;
	}
	string[index] = '\0';
	printf ("%s\n", string);
	index = 0;
	string = realloc(string, 15);
	while (index < 15)
	{
		string[index] = 'B';
		index++;
	}
	string[index] = '\0';
	printf ("%p : ", string);
	printf("%s", string);
	// the 2 printfs have to be the same (as the programm have to try to extend the size firstly
}
