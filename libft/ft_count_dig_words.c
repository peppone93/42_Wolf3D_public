/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_dig_words.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbianco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 17:31:11 by gbianco           #+#    #+#             */
/*   Updated: 2020/01/09 17:37:11 by gbianco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_dig_words(char *str, char c)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (str[i] != '\0')
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c && ft_isdigit(str[i]) == 1)
			n++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (n);
}
