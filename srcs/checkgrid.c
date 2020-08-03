/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkgrid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbianco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 14:35:59 by gbianco           #+#    #+#             */
/*   Updated: 2020/08/03 23:54:51 by gbianco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		check_grid(t_frame *t, t_vec2 *v)
{
	int x;
	int y;
	int value;

	x = (int)v->x >> 6;
	y = (int)v->y >> 6;
	if (x > 39 || x < 0 || y > 39 || y < 0)
		return (2);
	value = t->map[y * 40 + x];
	return (value);
}

int		check_grid_tx(t_frame *t, t_vec2 *v)
{
	float x;
	float y;
	float cosinus;

	cosinus = cos(t->cam.ang);
	x = (v->x + cosinus * 32) * 0.015625;
	y = v->y * 0.015625;
	if (x > 39 || x < 0 || y > 39 || y < 0)
		return (2);
	if (t->map[(int)y * 40 + (int)x] == 2)
		return (2);
	x = (cosinus > 0) ? x + (0.7 - cosinus) : x - (0.7 + cosinus);
	if (t->map[(int)y * 40 + (int)x] == 2)
		return (2);
	y += cosinus * 0.2;
	if (t->map[(int)y * 40 + (int)x] == 2)
		return (2);
	y -= cosinus * 0.4;
	if (t->map[(int)y * 40 + (int)x] == 2)
		return (2);
	return (0);
}

int		check_grid_ty(t_frame *t, t_vec2 *v)
{
	float x;
	float y;
	float sinus;

	sinus = sin(t->cam.ang);
	x = v->x * 0.015625;
	y = (v->y + sinus * 32) * 0.015625;
	if (x > 39 || x < 0 || y > 39 || y < 0)
		return (2);
	if (t->map[(int)y * 40 + (int)x] == 2)
		return (2);
	y = (sinus > 0) ? y + (0.7 - sinus) : y - (0.7 + sinus);
	if (t->map[(int)y * 40 + (int)x] == 2)
		return (2);
	x += sinus * 0.2;
	if (t->map[(int)y * 40 + (int)x] == 2)
		return (2);
	x -= sinus * 0.4;
	if (t->map[(int)y * 40 + (int)x] == 2)
		return (2);
	return (0);
}

int		check_grid_bx(t_frame *t, t_vec2 *v)
{
	float x;
	float y;
	float cosinus;

	cosinus = cos(t->cam.ang);
	x = (v->x - cosinus * 32) * 0.015625;
	y = v->y * 0.015625;
	if (x > 39 || x < 0 || y > 39 || y < 0)
		return (2);
	if (t->map[(int)y * 40 + (int)x] == 2)
		return (2);
	x = (cosinus > 0) ? x - (0.7 - cosinus) : x + (0.7 + cosinus);
	if (t->map[(int)y * 40 + (int)x] == 2)
		return (2);
	y += cosinus * 0.2;
	if (t->map[(int)y * 40 + (int)x] == 2)
		return (2);
	y -= cosinus * 0.4;
	if (t->map[(int)y * 40 + (int)x] == 2)
		return (2);
	return (0);
}

int		check_grid_by(t_frame *t, t_vec2 *v)
{
	float x;
	float y;
	float sinus;

	sinus = sin(t->cam.ang);
	x = v->x * 0.015625;
	y = (v->y - sinus * 32) * 0.015625;
	if (x > 39 || x < 0 || y > 39 || y < 0)
		return (2);
	if (t->map[(int)y * 40 + (int)x] == 2)
		return (2);
	y = (sinus > 0) ? y - (0.7 - sinus) : y + (0.7 + sinus);
	if (t->map[(int)y * 40 + (int)x] == 2)
		return (2);
	x += sinus * 0.2;
	if (t->map[(int)y * 40 + (int)x] == 2)
		return (2);
	x -= sinus * 0.4;
	if (t->map[(int)y * 40 + (int)x] == 2)
		return (2);
	return (0);
}
