/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbianco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 14:39:34 by gbianco           #+#    #+#             */
/*   Updated: 2020/08/03 23:38:40 by gbianco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	distance_coloring(t_frame *t, int reduction)
{
	unsigned int	base_clr;
	t_rgb			clr;

	base_clr = t->sdl.color;
	clr.r = (base_clr >> 24) - reduction;
	clr.g = ((base_clr >> 16) & 0xff) - reduction;
	clr.b = ((base_clr >> 8) & 0xff) - reduction;
	if (clr.r < 0)
		clr.r = 0;
	if (clr.g < 0)
		clr.g = 0;
	if (clr.b < 0)
		clr.b = 0;
	clr.t = 0xff0000ff & 0xff;
	t->sdl.color = ((clr.r << 24) | (clr.g << 16) | (clr.b << 8) | clr.t);
}

void	oriented_texture(t_frame *t, unsigned int **force)
{
	if (t->wall.side == 'h')
	{
		if (t->ray.quarter < 3)
			*force = (unsigned int*)t->sdl.walln->pixels;
		else
			*force = (unsigned int*)t->sdl.walls->pixels;
	}
	else
	{
		if (t->ray.quarter % 3 == 1)
			*force = (unsigned int*)t->sdl.walle->pixels;
		else
			*force = (unsigned int*)t->sdl.wallw->pixels;
	}
}

int		wall_texture(t_frame *t, float height, int i)
{
	unsigned int	*force;
	int				margin;
	int				x;
	int				y;

	if (t->wall.side == 'h')
		x = (int)t->wall.hit.x % 64;
	else
		x = (int)t->wall.hit.y % 64;
	margin = height - HEIGHT;
	if (margin > 0)
		i = i + (margin >> 1);
	y = 64. / height * i;
	force = NULL;
	oriented_texture(t, &force);
	t->sdl.color = (force[(y << 6) + x] << 8) + 0xff;
	distance_coloring(t, t->wall.dist * 0.05);
	return (t->sdl.color);
}

void	color_column(t_frame *t, float clm_height)
{
	int	wall_height;
	int index;
	int start;
	int i;

	wall_height = clm_height;
	if (clm_height > HEIGHT)
		clm_height = (float)HEIGHT;
	start = (float)HHEIGHT - clm_height * 0.5;
	t->wall.end = start + clm_height;
	index = start * WIDTH + t->wall.column - WIDTH;
	i = 0;
	while (start < t->wall.end)
	{
		index += WIDTH;
		t->sdl.pixels[index] = wall_texture(t, wall_height, i);
		start++;
		i++;
	}
}

void	trace_wall(t_frame *t)
{
	float wall_hei;

	t->wall.dist *= t->cam.ang_c[t->wall.column];
	wall_hei = t->wall.scaling / t->wall.dist;
	color_column(t, wall_hei);
}
