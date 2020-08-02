/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbianco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 21:51:49 by gbianco           #+#    #+#             */
/*   Updated: 2020/08/02 16:35:11 by gbianco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		top_atol(char const **str)
{
	int	sign;

	sign = 1;
	while (**str == ' ' || (**str >= 9 && **str <= 13))
		(*str)++;
	if (**str == '+' || **str == '-')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	if (**str > '9' || **str < '0')
		return (0);
	return (sign);
}

static long		bott_atol(char const **str)
{
	long	n;

	n = 0;
	while ((**str <= '9' && **str >= '0') && **str != '\0')
	{
		n = (n * 10) + ((**str) - 48);
		(*str)++;
	}
	return (n);
}

static double	calculate_decimal(char const *str)
{
	int		zeros;
	int		buff;
	double	decimal;

	zeros = 0;
	decimal = 0;
	if (*str == '\0' || *str != '.')
		return (0);
	str++;
	while (*str != '\0' && *str == '0')
	{
		zeros++;
		str++;
	}
	if (*str == '\0' || *str > '9' || *str < '0')
		return (0);
	decimal = bott_atol(&str);
	buff = ft_int_buffer(decimal) + zeros;
	while (buff)
	{
		decimal /= 10.;
		buff--;
	}
	return (decimal);
}

double			ft_atof(char const *str)
{
	char const	*s;
	double		left;
	double		right;
	int			check_sign;

	s = str;
	if ((check_sign = top_atol(&str)) == 0)
		return (0);
	left = bott_atol(&str);
	right = calculate_decimal(str);
	str = s;
	return ((left + right) * check_sign);
}
