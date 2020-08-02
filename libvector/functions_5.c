/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbianco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 16:39:10 by gbianco           #+#    #+#             */
/*   Updated: 2020/08/02 16:39:30 by gbianco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

double	v2_dot(t_vec2 v1, t_vec2 v2)
{
	return (v1.x * v2.x + v1.y * v2.y);
}

t_vec2	v2_dif(t_vec2 v1, t_vec2 v2)
{
	t_vec2 v;

	v.x = v1.x - v2.x;
	v.y = v1.y - v2.y;
	return (v);
}

double	v2_len(t_vec2 v1, t_vec2 v2)
{
	t_vec2 v;

	v = v2_dif(v2, v1);
	return (sqrt(v2_dot(v, v)));
}

double	v2_le2(t_vec2 v1, t_vec2 v2)
{
	t_vec2 v;

	v = v2_dif(v2, v1);
	return (v2_dot(v, v));
}

t_vec2	v2(double x, double y)
{
	t_vec2 v;

	v.x = x;
	v.y = y;
	return (v);
}
