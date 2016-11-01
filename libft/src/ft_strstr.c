/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 14:53:52 by pbourdon          #+#    #+#             */
/*   Updated: 2015/11/27 16:39:23 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		test(char *str1, char *str2, int nbr)
{
	int		a;
	int		test;

	test = 1;
	a = 0;
	while (a < nbr)
	{
		if (str1[a] != str2[a])
			return (0);
		a++;
	}
	return (test);
}

char	*ft_strstr(const char *s1, const char *s2)
{
	int		a;
	int		c;
	int		b;
	char	*str1;
	char	*str2;

	str1 = (char *)s1;
	str2 = (char *)s2;
	a = 0;
	c = 0;
	b = 0;
	if (!*str2)
		return (str1);
	while (str2[c] != '\0')
		c++;
	while (str1[a] != '\0')
	{
		if (str1[a] == str2[b])
			if (test(str1 + a, str2, c) == 1)
				return (str1 + a);
		a++;
	}
	return (NULL);
}
