/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbianco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 18:27:43 by gbianco           #+#    #+#             */
/*   Updated: 2020/08/02 16:22:12 by gbianco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	sdl_cleaner(t_sdl *sdl)
{
	SDL_FreeSurface(sdl->srf);
	SDL_FreeSurface(sdl->sky);
	SDL_FreeSurface(sdl->walln);
	SDL_FreeSurface(sdl->walls);
	SDL_FreeSurface(sdl->walle);
	SDL_FreeSurface(sdl->wallw);
	SDL_FreeSurface(sdl->grnd);
	SDL_FreeSurface(sdl->clt);
	SDL_RenderClear(sdl->rnd);
	SDL_DestroyRenderer(sdl->rnd);
	SDL_DestroyWindow(sdl->win);
	SDL_QuitSubSystem(SDL_INIT_EVENTS);
	SDL_QuitSubSystem(SDL_INIT_VIDEO);
	SDL_VideoQuit();
	SDL_Quit();
}

void	sdl_error(t_sdl *sdl, const char *error)
{
	ft_putstr((const char*)error);
	ft_putchar('\n');
	sdl_cleaner(sdl);
	exit(EXIT_FAILURE);
}

int		sdl_exit(t_frame *t)
{
	if (t->sdl.events.type == SDL_QUIT)
		return (1);
	if (t->sdl.events.type == SDL_KEYDOWN)
		if (t->sdl.events.key.keysym.sym == T_ESC)
			return (1);
	return (0);
}

void	sdl_put_surface(t_sdl *sdl)
{
	sdl->txt = SDL_CreateTextureFromSurface(sdl->rnd, sdl->srf);
	if (sdl->txt == NULL)
		sdl_error(sdl, SDL_GetError());
	SDL_SetTextureBlendMode(sdl->txt, SDL_BLENDMODE_NONE);
	if (SDL_RenderCopy(sdl->rnd, sdl->txt, NULL, NULL) != 0)
		sdl_error(sdl, SDL_GetError());
	SDL_DestroyTexture(sdl->txt);
	sdl->txt = NULL;
	SDL_RenderPresent(sdl->rnd);
}

void	sdl_init(t_sdl *sdl)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		sdl_error(sdl, SDL_GetError());
	ft_bzero(&sdl->key, sizeof(t_key));
	sdl->win = SDL_CreateWindow("Wolf3D", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	if (sdl->win == NULL)
		sdl_error(sdl, SDL_GetError());
	sdl->rnd = SDL_CreateRenderer(sdl->win, -1, 0);
	if (sdl->rnd == NULL)
		sdl_error(sdl, SDL_GetError());
	sdl->srf = SDL_CreateRGBSurface(0, WIDTH, HEIGHT, 32, 0xff000000,
			0x00ff0000, 0x0000ff00, 0x000000ff);
	if (sdl->srf == NULL)
		sdl_error(sdl, SDL_GetError());
	sdl->pixels = (unsigned int*)sdl->srf->pixels;
}
