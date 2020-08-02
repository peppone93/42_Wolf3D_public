/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbianco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 14:48:52 by gbianco           #+#    #+#             */
/*   Updated: 2020/08/02 16:38:10 by gbianco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	base_number_dim(int value, int base)
{
	int			dim;
	long int	temp;

	temp = value;
	dim = 0;
	if (temp < 0)
	{
		if (base == 10)
			dim++;
		temp *= -1;
	}
	if (temp == 0)
		dim++;
	while (temp > 0)
	{
		dim++;
		temp /= base;
	}
	return (dim);
}

char		*ft_itoa_base(int value, int base)
{
	char	*number;
	long	temp;
	int		dim;

	temp = value;
	dim = base_number_dim(temp, base);
	number = (char*)malloc((dim + 1) * sizeof(char));
	number[dim] = '\0';
	if (temp < 0 && base == 10)
		number[0] = '-';
	if (temp < 0)
		temp = temp * -1;
	while (dim)
	{
		if (number[dim - 1] != '-')
		{
			if (temp % base < 10)
				number[dim - 1] = (temp % base) + '0';
			else
				number[dim - 1] = (temp % base) + 55;
		}
		temp = temp / base;
		dim--;
	}
	return (number);
}
