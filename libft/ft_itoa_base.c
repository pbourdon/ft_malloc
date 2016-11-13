/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 13:32:22 by pbourdon          #+#    #+#             */
/*   Updated: 2016/10/31 14:37:59 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa_base(int value, int base)
{
	char base_digits[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
	int converted_number[64];
	int i = 0;
	int n;
	char *result;

	if (value == 2147483647 && base == 10)
		return ("2147483647");
	if (value == -2147483648 && base == 10)
		return ("-2147483648");
	if (value == 0)
		return ("0");
	n = value;
	if (value < 0)
		value = value * -1;
	while (value != 0)
	{
		converted_number[i] = value % base;
		value = value / base;
		++i;
	}
	--i;
	result = malloc(i * sizeof(char));
	if (n < 0 && base == 10)
	{
		result[0] = '-';
		n = 1;
	}
	else
		n = 0;
	while (i >= 0)
	{
		result[n] = base_digits[converted_number[i]];
		i--;
		n++;
	}
	result[n] = '\0';
	return (result);
}
