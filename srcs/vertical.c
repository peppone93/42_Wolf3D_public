/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbianco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 14:39:10 by gbianco           #+#    #+#             */
/*   Updated: 2020/08/03 22:30:05 by gbianco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	sprite_vertical_intersection(t_frame *t)
{
	float y;
	float y2;
	float dist;

	y = t->ray.pos.y * 0.015625;
	y2 = (int)y;
	y2 += 0.5;
	if (fabs(y2 - y) < SENSSPR)
	{
		dist = (v2_len(t->ray.pos, t->plr.pos));
		t->spr.check_v = 1;
	}
	else
		return ;
	if (t->spr.cltd[t->wall.column] == -1)
		t->spr.cltd[t->wall.column] = dist;
	else
	{
		if (dist < t->spr.cltd[t->wall.column])
			t->spr.cltd[t->wall.column] = dist;
	}
}

void	sprite_vertical(t_frame *t)
{
	t_vec2 p;

	if (t->ray.quarter % 3 == 1)
	{
		vertical_rightdir(t, &p, 32);
		if ((check_grid(t, &t->ray.pos) == 3))
			sprite_vertical_intersection(t);
		vertical_rightdir(t, &p, 32);
	}
	else
	{
		vertical_leftdir(t, &p, 32);
		if ((check_grid(t, &t->ray.pos) == 3))
			sprite_vertical_intersection(t);
		vertical_leftdir(t, &p, 32);
	}
}

void	vertical_rightdir(t_frame *t, t_vec2 *p, int n)
{
	if (t->wall.check_v == 0)
	{
		p->x = (int)(t->ray.pos.x / (float)n + 1);
		p->x = p->x * (float)n;
		p->y = t->ray.pos.y + (p->x - t->ray.pos.x) * tan(t->ray.angle);
		t->ray.pos.x = p->x;
		t->ray.pos.y = p->y;
		t->wall.check_v = 1;
		return ;
	}
	p->x = (float)n;
	p->y = p->x * tan(t->ray.angle);
	t->ray.pos.x += p->x;
	t->ray.pos.y += p->y;
}

void	vertical_leftdir(t_frame *t, t_vec2 *p, int n)
{
	if (t->wall.check_v == 0)
	{
		p->x = (int)(t->ray.pos.x / (float)n);
		p->x = p->x * (float)n - 0.000001;
		p->y = t->ray.pos.y + (p->x - t->ray.pos.x) * tan(t->ray.angle);
		t->ray.pos.x = p->x;
		t->ray.pos.y = p->y;
		t->wall.check_v = 1;
		return ;
	}
	p->x = -(float)n;
	p->y = p->x * tan(t->ray.angle);
	t->ray.pos.x += p->x;
	t->ray.pos.y += p->y;
}

float	vertical_intersections(t_frame *t)
{
	t_vec2	p;
	int		check;

	if (t->ray.quarter % 3 == 1)
		vertical_rightdir(t, &p, 64);
	else
		vertical_leftdir(t, &p, 64);
	check = check_grid(t, &t->ray.pos);
	if (check == 3 && t->spr.check_v == 0)
	{
		sprite_vertical(t);
		check = check_grid(t, &t->ray.pos);
	}
	if (check == 2)
	{
		t->wall.hit.y = t->ray.pos.y;
		return (v2_len(t->ray.pos, t->plr.pos));
	}
	else
		return (vertical_intersections(t));
}
