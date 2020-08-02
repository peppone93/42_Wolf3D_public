/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbianco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 18:46:14 by gbianco           #+#    #+#             */
/*   Updated: 2020/08/02 14:55:54 by gbianco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	assign_value_map(t_frame *t, unsigned int *color, int *plr, int *i)
{
	if (*color == 0xffffffff)
		t->map[*i] = 0;
	else if (*color == 0xff0000ff)
		t->map[*i] = 2;
	else if (*color == 0xffffff00)
	{
		t->map[*i] = 3;
		t->spr.cnt = (t->spr.cnt == -1) ? 1 : t->spr.cnt + 1;
	}
	else if (*color == 0xffff0000)
	{
		t->map[*i] = 1;
		t->plr.pos.y = (int)(*i / 40);
		t->plr.pos.x = *i - (t->plr.pos.y * 40);
		t->plr.pos.y += 0.5;
		t->plr.pos.x += 0.5;
		(*plr)++;
	}
	else
		sdl_error(&t->sdl, "Invalid map");
}

void	convert_map(t_frame *t)
{
	unsigned int	color;
	int				i;
	int				x;
	int				y;
	int				plr;

	i = 0;
	y = 8;
	plr = 0;
	while (y < WIDTH)
	{
		x = 8;
		while (x < WIDTH)
		{
			color = t->sdl.pixels[(639 - y) * WIDTH + x];
			assign_value_map(t, &color, &plr, &i);
			i++;
			x += 16;
		}
		y += 16;
	}
	if (plr != 1)
		sdl_error(&t->sdl, "Invalid character position");
}

void	read_map(t_frame *t)
{
	t->sdl.srf = SDL_LoadBMP(t->pth.map);
	if (t->sdl.srf == NULL)
		sdl_error(&t->sdl, SDL_GetError());
	t->sdl.pixels = (unsigned int*)t->sdl.srf->pixels;
	t->spr.cnt = -1;
	convert_map(t);
	SDL_FreeSurface(t->sdl.srf);
	t->sdl.srf = NULL;
	t->sdl.pixels = NULL;
}
