/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbianco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 14:40:13 by gbianco           #+#    #+#             */
/*   Updated: 2020/08/02 16:23:12 by gbianco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	sdl_setkeys(t_frame *t)
{
	if (t->sdl.events.type == SDL_KEYUP)
	{
		if (t->sdl.events.key.keysym.sym == T_TOP)
			t->sdl.key.top = 0;
		if (t->sdl.events.key.keysym.sym == T_BOT)
			t->sdl.key.bot = 0;
		if (t->sdl.events.key.keysym.sym == T_RHT)
			t->sdl.key.rht = 0;
		if (t->sdl.events.key.keysym.sym == T_LFT)
			t->sdl.key.lft = 0;
	}
	if (t->sdl.events.type == SDL_KEYDOWN)
	{
		if (t->sdl.events.key.keysym.sym == T_TOP)
			t->sdl.key.top = 1;
		if (t->sdl.events.key.keysym.sym == T_BOT)
			t->sdl.key.bot = 1;
		if (t->sdl.events.key.keysym.sym == T_RHT)
			t->sdl.key.rht = 1;
		if (t->sdl.events.key.keysym.sym == T_LFT)
			t->sdl.key.lft = 1;
	}
}

int		continuously_collisions_top(t_frame *t)
{
	int check;

	check = 0;
	if (check_grid_tx(t, &t->plr.pos) != 2)
	{
		t->plr.pos.x = t->plr.pos.x + cos(t->cam.ang) * SPEED;
		check = 1;
	}
	if (check_grid_ty(t, &t->plr.pos) != 2)
	{
		t->plr.pos.y = t->plr.pos.y + sin(t->cam.ang) * SPEED;
		check = 1;
	}
	if (check == 1)
		return (1);
	return (0);
}

int		continuously_collisions_bot(t_frame *t)
{
	int check;

	check = 0;
	if (check_grid_bx(t, &t->plr.pos) != 2)
	{
		t->plr.pos.x = t->plr.pos.x - cos(t->cam.ang) * SPEED;
		check = 1;
	}
	if (check_grid_by(t, &t->plr.pos) != 2)
	{
		t->plr.pos.y = t->plr.pos.y - sin(t->cam.ang) * SPEED;
		check = 1;
	}
	if (check == 1)
		return (1);
	return (0);
}

void	sdl_handekeys(t_frame *t)
{
	char	check;

	check = 0;
	if (t->sdl.key.top == 1)
		check = continuously_collisions_top(t);
	if (t->sdl.key.bot == 1)
		check = continuously_collisions_bot(t);
	if (check == 1)
		remove_sprite(t);
	if (t->sdl.key.rht == 1)
	{
		protected_dif(&t->cam.ang, 0.008 * SPEED);
		check = 1;
	}
	if (t->sdl.key.lft == 1)
	{
		protected_sum(&t->cam.ang, 0.008 * SPEED);
		check = 1;
	}
	if (check == 1)
	{
		start_casting(t);
	}
}

void	sdl_wait(t_frame *t)
{
	while (CONTINUE)
	{
		sdl_setkeys(t);
		sdl_handekeys(t);
		SDL_PollEvent(&t->sdl.events);
		if (sdl_exit(t) == 1)
			break ;
	}
}
