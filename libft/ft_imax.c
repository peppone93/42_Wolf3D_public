/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imax.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbianco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 21:40:00 by gbianco           #+#    #+#             */
/*   Updated: 2019/12/27 21:40:27 by gbianco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_imax(int *n, double max)
{
	*n = *n > max ? max : *n;
}