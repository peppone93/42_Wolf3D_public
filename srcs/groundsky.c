/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   groundsky.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbianco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 19:41:27 by gbianco           #+#    #+#             */
/*   Updated: 2020/08/03 23:37:31 by gbianco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			draw_ground_b(t_frame *t, t_vec2 *w, int *index)
{
	unsigned int	*floor;
	int				cx;
	int				cy;

	floor = (unsigned int*)t->sdl.grnd->pixels;
	cx = (int)w->x % 128;
	cy = (int)w->y % 128;
	if (cx < 0)
		cx = 0;
	if (cy < 0)
		cy = 0;
	t->sdl.color = floor[(cy << 7) + cx] << 8 | 0xff;
	distance_coloring(t, (HEIGHT - t->wall.end) * 0.4);
	t->sdl.pixels[*index] = t->sdl.color;
}

void			draw_ground(t_frame *t)
{
	int		index;
	float	world_dist;
	t_vec2	world;

	index = t->wall.end * WIDTH + t->wall.column;
	t->wall.end -= 1;
	while (++t->wall.end < HEIGHT)
	{
		world_dist = (32. / (t->wall.end - (float)HHEIGHT));
		world_dist = t->cam.dist * world_dist / t->cam.ang_c[t->wall.column];
		world.x = world_dist * cos(t->ray.angle) * SENSGRN + t->plr.pos.x;
		world.y = world_dist * sin(t->ray.angle) * SENSGRN + t->plr.pos.y;
		draw_ground_b(t, &world, &index);
		index += WIDTH;
	}
}

void			draw_sky(t_frame *t)
{
	unsigned int	*force_cast;
	int				i;
	int				max;

	max = WIDTH * HEIGHT;
	force_cast = (unsigned int*)t->sdl.sky->pixels;
	i = -1;
	while (++i < max)
		t->sdl.pixels[i] = force_cast[i];
}

unsigned int	generate_sky_b(t_frame *t, int reduction)
{
	t_rgb clr;

	clr.b = ((t->sdl.color >> 8) & 0xff) - (reduction >> 2);
	if (t->sdl.color == GREY)
		reduction = reduction >> 2;
	else if (t->sdl.color == VIOLET)
		reduction = reduction >> 1;
	clr.r = ((t->sdl.color >> 24) & 0xff) - reduction;
	clr.g = ((t->sdl.color >> 16) & 0xff) - reduction;
	clr.t = 0xff;
	clr.r = clr.r > 0 ? clr.r : 0;
	clr.g = clr.g > 0 ? clr.g : 0;
	clr.b = clr.b > 0 ? clr.b : 0;
	return ((clr.r << 24) | (clr.g << 16) | (clr.b << 8) | clr.t);
}

void			generate_sky(t_frame *t)
{
	int	i;
	int x;
	int line;
	int color;

	t->sdl.sky = SDL_CreateRGBSurface(0, WIDTH, HEIGHT, 32, 0xff000000,
			0x00ff0000, 0x0000ff00, 0x000000ff);
	if (t->sdl.sky == NULL)
		sdl_error(&t->sdl, SDL_GetError());
	line = -1;
	while (++line < HHEIGHT)
	{
		x = line * WIDTH;
		color = generate_sky_b(t, line);
		i = -1;
		while (++i < WIDTH)
			((unsigned int*)t->sdl.sky->pixels)[x + i] = color;
	}
}
