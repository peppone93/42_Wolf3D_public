/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbianco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 14:39:21 by gbianco           #+#    #+#             */
/*   Updated: 2020/08/03 23:51:47 by gbianco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	put_points(t_frame *t)
{
	int points;
	int start;
	int	i;
	int j;
	int m;

	points = t->spr.cnt + 1;
	start = 8;
	while (--points > 0)
	{
		j = -1;
		while (++j < 3)
		{
			i = -1;
			m = (j + 5) * WIDTH;
			while (++i < 6)
				t->sdl.pixels[m + (i + start)] = t->spr.clr_pnt;
		}
		start += 10;
	}
}

void	remove_sprite(t_frame *t)
{
	int x;
	int y;

	if (check_grid(t, &t->plr.pos) == 3)
	{
		x = (int)t->plr.pos.x >> 6;
		y = (int)t->plr.pos.y >> 6;
		t->map[y * 40 + x] = 0;
		t->spr.cnt--;
		if (t->spr.cnt == 0)
		{
			sdl_cleaner(&t->sdl);
			exit(EXIT_SUCCESS);
		}
	}
}

void	uv_quad(t_frame *t, t_quad *q, float div, int idx)
{
	unsigned int	*texels;
	unsigned int	color;
	int				u;
	int				v;

	(q->v)++;
	texels = (unsigned int*)t->sdl.clt->pixels;
	u = q->u * div;
	v = q->v * div;
	color = texels[(u << 6) + v] << 8;
	if (t->spr.cltd[q->center] < t->spr.wlld[q->left])
		if (color != 0 && q->left > 0 && q->left < 640)
			t->sdl.pixels[idx + q->left] = color;
}

void	draw_sprite_quad(t_frame *t, int center)
{
	t_quad	q;
	int		idx;
	float	div;

	q.center = center;
	q.side = 1. / t->spr.cltd[center] * DISTSPR;
	q.side = (q.side % 2 == 0) ? q.side : q.side + 1;
	q.hside = q.side / 2;
	q.right = center + q.hside;
	q.top = HHEIGHT - q.hside - 1;
	q.bot = HHEIGHT + q.hside;
	div = 64. / (float)q.side;
	idx = q.top * WIDTH;
	q.u = 0;
	while (++q.top < q.bot)
	{
		q.v = -1;
		q.left = center - q.hside - 1;
		while (++q.left < q.right)
			uv_quad(t, &q, div, idx);
		idx += WIDTH;
		q.u++;
	}
}

void	put_sprites(t_frame *t)
{
	int dist[WIDTH];
	int center[WIDTH];
	int i;

	sort_sprites(t, dist, center);
	i = -1;
	while (dist[++i] != -1)
		draw_sprite_quad(t, center_sprites(dist, center, &i));
}
