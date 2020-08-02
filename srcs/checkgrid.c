/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkgrid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbianco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 14:35:59 by gbianco           #+#    #+#             */
/*   Updated: 2020/08/02 14:49:14 by gbianco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		check_grid(t_frame *t, t_vec2 *v)
{
	int x;
	int y;
	int value;

	x = (int)(v->x / 64.);
	y = (int)(v->y / 64.);
	if (x > 39 || x < 0 || y > 39 || y < 0)
		return (2);
	value = t->map[y * 40 + x];
	return (value);
}

int		check_grid_x(t_frame *t, t_vec2 *v)
{
	double x;
	double y;
	double angle;

	x = (v->x + cos(t->cam.ang) * 40) / 64.;
	y = v->y / 64.;
	if (x > 39 || x < 0 || y > 39 || y < 0)
		return (2);
	if (t->map[(int)y * 40 + (int)x] == 2)
		return (2);
	angle = t->cam.ang + 22. * DEGTORAD;
	x = (v->x + cos(angle) * 60) / 64.;
	if (t->map[(int)y * 40 + (int)x] == 2)
		return (2);
	angle = t->cam.ang - 22. * DEGTORAD;
	x = (v->x + cos(angle) * 60) / 64.;
	if (t->map[(int)y * 40 + (int)x] == 2)
		return (2);
	return (0);
}

int		check_grid_y(t_frame *t, t_vec2 *v)
{
	double x;
	double y;
	double angle;

	x = v->x / 64.;
	y = (v->y + sin(t->cam.ang) * 40) / 64.;
	if (x > 39 || x < 0 || y > 39 || y < 0)
		return (2);
	if (t->map[(int)y * 40 + (int)x] == 2)
		return (2);
	angle = t->cam.ang + 22. * DEGTORAD;
	y = (v->y + sin(angle) * 60) / 64.;
	if (t->map[(int)y * 40 + (int)x] == 2)
		return (2);
	angle = t->cam.ang - 22. * DEGTORAD;
	y = (v->y + sin(angle) * 60) / 64.;
	if (t->map[(int)y * 40 + (int)x] == 2)
		return (2);
	return (0);
}
