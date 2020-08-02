/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbianco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 19:53:39 by gbianco           #+#    #+#             */
/*   Updated: 2020/08/02 16:37:05 by gbianco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_buffer(long buff)
{
	int count;

	count = 0;
	while (buff)
	{
		buff /= 10;
		count++;
	}
	return (count);
}

static void	count_decimal(double *right, int *decimal)
{
	*right = *right * ft_power(10, PRECISION);
	*right = (long)(*right + 0.5);
	*decimal = int_buffer(*right);
}

static void	decimal_part(char *str, long right, int *buffer, int zeros)
{
	while (right)
	{
		str[--(*buffer)] = (right % 10) + 48;
		right = right / 10;
	}
	while (--zeros > 0)
		str[--(*buffer)] = '0';
	str[--(*buffer)] = '.';
}

static char	*alloc_string(long left, long right, int sign, int decimal)
{
	char	*str;
	int		zeros;
	int		buffer;

	zeros = PRECISION - decimal;
	buffer = sign + ft_int_buffer(left);
	if (decimal > 0)
		buffer += 1 + PRECISION;
	str = (char*)ft_secmemalloc(sizeof(char) * (buffer + 1));
	str[0] = (sign == 1) ? '-' : '0';
	str[1] = '0';
	str[buffer] = '\0';
	if (decimal > 0)
		decimal_part(str, right, &buffer, zeros + 1);
	while (left)
	{
		str[--buffer] = (left % 10) + 48;
		left = left / 10;
	}
	return (str);
}

char		*ft_ftoa(double n)
{
	double	right;
	long	left;
	int		sign;
	int		decimal;

	sign = (n < 0) ? 1 : 0;
	left = (long)n;
	right = fabs(n - left);
	left = labs(left);
	decimal = 0;
	count_decimal(&right, &decimal);
	return (alloc_string(left, (long)right, sign, decimal));
}
