/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbianco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 14:39:40 by gbianco           #+#    #+#             */
/*   Updated: 2020/08/02 14:39:42 by gbianco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	protected_dif(double *angle, double dif)
{
	*angle -= dif;
	if (*angle < 0)
		*angle = RADCIRC - -*angle;
}

void	protected_sum(double *angle, double sum)
{
	*angle += sum;
	if (*angle > RADCIRC)
		*angle = *angle - RADCIRC;
}
