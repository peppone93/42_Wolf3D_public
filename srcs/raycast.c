/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbianco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 19:33:35 by gbianco           #+#    #+#             */
/*   Updated: 2020/08/02 16:21:42 by gbianco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	cast_ray(t_frame *t)
{
	double hor_dist;
	double ver_dist;

	hor_dist = horizontal_intersections(t);
	t->ray.pos.x = t->plr.pos.x;
	t->ray.pos.y = t->plr.pos.y;
	ver_dist = vertical_intersections(t);
	if (hor_dist < ver_dist)
	{
		t->wall.dist = hor_dist;
		t->wall.side = 'h';
	}
	else
	{
		t->wall.dist = ver_dist;
		t->wall.side = 'v';
	}
	t->spr.wlld[t->wall.column] = t->wall.dist;
}

void	assign_ray_quarter(t_frame *t)
{
	if (t->ray.angle > RADHALF)
	{
		if (t->ray.angle > RADTHIR)
			t->ray.quarter = 4;
		else
			t->ray.quarter = 3;
	}
	else
	{
		if (t->ray.angle > RADQUAD)
			t->ray.quarter = 2;
		else
			t->ray.quarter = 1;
	}
}

void	reset_column(t_frame *t)
{
	t->spr.cltd[t->wall.column] = -1;
	t->wall.check_h = 0;
	t->wall.check_v = 0;
	t->spr.check_h = 0;
	t->spr.check_v = 0;
	t->ray.pos.x = t->plr.pos.x;
	t->ray.pos.y = t->plr.pos.y;
}

void	start_casting(t_frame *t)
{
	draw_sky(t);
	t->ray.angle = t->cam.ang;
	t->cam.ang_c = -(HRADFOV);
	protected_sum(&t->ray.angle, HRADFOV);
	t->wall.column = -1;
	while (++t->wall.column < WIDTH)
	{
		reset_column(t);
		assign_ray_quarter(t);
		cast_ray(t);
		trace_wall(t);
		draw_ground(t);
		protected_dif(&t->ray.angle, t->cam.ang_u);
		t->cam.ang_c += t->cam.ang_u;
	}
	put_sprites(t);
	put_points(t);
	sdl_put_surface(&t->sdl);
}
