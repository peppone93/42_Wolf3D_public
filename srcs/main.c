/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbianco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 18:22:14 by gbianco           #+#    #+#             */
/*   Updated: 2020/08/02 14:54:41 by gbianco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	error(t_frame *t, char *str)
{
	sdl_cleaner(&t->sdl);
	ft_putstr(str);
	ft_putchar('\n');
	exit(EXIT_FAILURE);
}

void	txt_path_init(t_frame *t)
{
	if ((t->sdl.grnd = SDL_LoadBMP(t->pth.tx[0])) == NULL)
		sdl_error(&t->sdl, SDL_GetError());
	if ((t->sdl.walln = SDL_LoadBMP(t->pth.tx[1])) == NULL)
		sdl_error(&t->sdl, SDL_GetError());
	if ((t->sdl.walls = SDL_LoadBMP(t->pth.tx[2])) == NULL)
		sdl_error(&t->sdl, SDL_GetError());
	if ((t->sdl.walle = SDL_LoadBMP(t->pth.tx[3])) == NULL)
		sdl_error(&t->sdl, SDL_GetError());
	if ((t->sdl.wallw = SDL_LoadBMP(t->pth.tx[4])) == NULL)
		sdl_error(&t->sdl, SDL_GetError());
	if ((t->sdl.clt = SDL_LoadBMP(t->pth.tx[5])) == NULL)
		sdl_error(&t->sdl, SDL_GetError());
}

void	scene_init(t_frame *t)
{
	t->plr.pos.x *= 64.;
	t->plr.pos.y *= 64.;
	t->cam.ang = RADQUAD;
	t->cam.dist = ((double)HWIDTH) / tan(HRADFOV);
	t->wall.scaling = 64. * t->cam.dist;
	t->cam.ang_u = RADFOV / (double)WIDTH;
	generate_sky(t);
	txt_path_init(t);
	t->spr.clr_pnt = ((unsigned int*)t->sdl.clt->pixels)[695];
}

int		main(int ac, char **av)
{
	t_frame	t;

	ft_bzero(&t, sizeof(t_frame));
	read_arguments(&t, ac, av);
	read_map(&t);
	sdl_init(&t.sdl);
	scene_init(&t);
	start_casting(&t);
	sdl_wait(&t);
	sdl_cleaner(&t.sdl);
	return (0);
}
