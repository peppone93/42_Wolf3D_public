/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbianco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 14:39:04 by gbianco           #+#    #+#             */
/*   Updated: 2020/08/02 14:54:08 by gbianco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	sprite_horizontal_intersection(t_frame *t)
{
	double x;
	double x2;

	x = t->ray.pos.x / 64.;
	x2 = (int)x;
	x2 += 0.5;
	if (fabs(x2 - x) < SENSSPR)
	{
		t->spr.cltd[t->wall.column] = (v2_len(t->ray.pos, t->plr.pos));
		t->spr.check_h = 1;
	}
}

void	sprite_horizontal(t_frame *t)
{
	t_vec2 p;

	if (t->ray.quarter < 3)
	{
		horizontal_updir(t, &p, 32);
		if ((check_grid(t, &t->ray.pos) == 3))
			sprite_horizontal_intersection(t);
		horizontal_updir(t, &p, 32);
	}
	else
	{
		horizontal_downdir(t, &p, 32);
		if ((check_grid(t, &t->ray.pos) == 3))
			sprite_horizontal_intersection(t);
		horizontal_downdir(t, &p, 32);
	}
}

void	horizontal_updir(t_frame *t, t_vec2 *p, int n)
{
	if (t->wall.check_h == 0)
	{
		p->y = (int)(t->ray.pos.y / (double)n + 1);
		p->y = p->y * (double)n;
		p->x = t->ray.pos.x + (p->y - t->ray.pos.y) / tan(t->ray.angle);
		t->ray.pos.x = p->x;
		t->ray.pos.y = p->y;
		t->wall.check_h = 1;
		return ;
	}
	p->y = (double)n;
	p->x = p->y / tan(t->ray.angle);
	t->ray.pos.x += p->x;
	t->ray.pos.y += p->y;
}

void	horizontal_downdir(t_frame *t, t_vec2 *p, int n)
{
	if (t->wall.check_h == 0)
	{
		p->y = (int)(t->ray.pos.y / (double)n);
		p->y = p->y * (double)n - 0.000001;
		p->x = t->ray.pos.x + (p->y - t->ray.pos.y) / tan(t->ray.angle);
		t->ray.pos.x = p->x;
		t->ray.pos.y = p->y;
		t->wall.check_h = 1;
		return ;
	}
	p->y = -(double)n;
	p->x = p->y / tan(t->ray.angle);
	t->ray.pos.x += p->x;
	t->ray.pos.y += p->y;
}

double	horizontal_intersections(t_frame *t)
{
	t_vec2	p;
	int		check;

	if (t->ray.quarter < 3)
		horizontal_updir(t, &p, 64);
	else
		horizontal_downdir(t, &p, 64);
	check = check_grid(t, &t->ray.pos);
	if (check == 3 && t->spr.check_h == 0)
	{
		sprite_horizontal(t);
		check = check_grid(t, &t->ray.pos);
	}
	if (check == 2)
	{
		t->wall.hit.x = t->ray.pos.x;
		return (v2_len(t->ray.pos, t->plr.pos));
	}
	else
		return (horizontal_intersections(t));
}
