/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 13:32:22 by pbourdon          #+#    #+#             */
/*   Updated: 2016/11/22 12:15:31 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base_exceptions(int value, int base)
{
	if (value == 2147483647 && base == 10)
	{
		return ("2147483647");
	}
	if (value == -2147483648 && base == 10)
	{
		return ("-2147483648");
	}
	if (value == 0)
	{
		return ("0");
	}
	return (0);
}

char	*ft_tabb(char *base_digits)
{
	base_digits[0] = '0';
	base_digits[1] = '1';
	base_digits[2] = '2';
	base_digits[3] = '3';
	base_digits[4] = '4';
	base_digits[5] = '5';
	base_digits[6] = '6';
	base_digits[7] = '7';
	base_digits[8] = '8';
	base_digits[9] = '9';
	base_digits[10] = 'A';
	base_digits[11] = 'B';
	base_digits[12] = 'C';
	base_digits[13] = 'D';
	base_digits[14] = 'E';
	base_digits[15] = 'F';
	return (base_digits);
}

char	*ft_itoa_base2(int value, int base, char *result, char *base_digits)
{
	int converted_number[64];
	int n;
	int i;

	base_digits = ft_tabb(base_digits);
	n = 0;
	i = 0;
	if (((value == 2147483647 || value == -2147483648) && base == 10) ||
			value == 0)
		return (ft_itoa_base_exceptions(value, base));
	while (value != 0)
	{
		converted_number[i] = value % base;
		value = value / base;
		++i;
	}
	--i;
	while (i >= 0)
	{
		result[n] = base_digits[converted_number[i]];
		i--;
		n++;
	}
	result[n] = '\0';
	return (result);
}
