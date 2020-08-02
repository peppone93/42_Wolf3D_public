/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbianco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 00:40:26 by gbianco           #+#    #+#             */
/*   Updated: 2020/01/12 01:21:13 by gbianco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *str)
{
	long		n;
	long		neg;
	const char	*st;

	st = str;
	n = 0;
	neg = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	if (*str > '9' || *str < '0')
		return (0);
	while ((*str <= '9' && *str >= '0') && *str != '\0')
	{
		n = (n * 10) + ((*str) - 48);
		str++;
	}
	str = st;
	return (n * neg);
}
