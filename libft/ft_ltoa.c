/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbianco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 00:06:17 by gbianco           #+#    #+#             */
/*   Updated: 2020/01/12 00:27:05 by gbianco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_ltoa(long nb)
{
	char		*string;
	int			buffer;

	buffer = ft_int_buffer(nb);
	if (!(string = ft_strnew(buffer)))
		return (NULL);
	string[buffer] = '\0';
	if (nb == 0)
		string[0] = '0';
	while (nb)
	{
		if (nb < 0)
		{
			string[0] = '-';
			nb = nb * -1;
		}
		string[buffer - 1] = (nb % 10) + 48;
		nb = nb / 10;
		buffer--;
	}
	return (string);
}
