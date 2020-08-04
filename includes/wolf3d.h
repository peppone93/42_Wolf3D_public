/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbianco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 19:42:14 by gbianco           #+#    #+#             */
/*   Updated: 2020/08/05 15:48:23 by gbianco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "SDL.h"
# include "libft.h"
# include "vec.h"

# define DEGTORAD 0.017453292519943
# define RADTODEG 57.29577951308232

# define DEGFOV	60.0
# define RADFOV	1.04719755119658
# define HDEGFOV 30.0
# define HRADFOV 0.52359877559829
# define UNTCOSC 0.000781249999995

# define DEGQUAD 90.0
# define RADQUAD 1.570796326794897
# define DEGHALF 180.
# define RADHALF 3.141592653589793
# define DEGTHIR 270.
# define RADTHIR 4.712388980384691
# define DEGCIRC 360.
# define RADCIRC 6.283185307179586

# define DISTSPR 12000
# define SENSSPR 0.015
# define SENSGRN 0.965
# define MAXSPRT 25
# define SPEED 4.4
# define STOPR 32

# define WIDTH 640
# define HEIGHT 480
# define HWIDTH 320
# define HHEIGHT 240

# define T_ESC 27
# define T_TOP 1073741906
# define T_BOT 1073741905
# define T_LFT 1073741904
# define T_RHT 1073741903

# define VIOLET 0x660055ff
# define GREEN 0xaffe00ff
# define GREY 0x333333ff

# define CONTINUE 1

typedef struct		s_rgbmask
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	unsigned int	t;
}					t_rgbmask;

typedef struct		s_rgb
{
	int				r;
	int				g;
	int				b;
	int				t;
}					t_rgb;

typedef struct		s_quad
{
	int				center;
	int				side;
	int				hside;
	int				left;
	int				top;
	int				right;
	int				bot;
	int				u;
	int				v;
}					t_quad;

typedef struct		s_key
{
	char			top;
	char			bot;
	char			lft;
	char			rht;
}					t_key;

typedef struct		s_sdl
{
	unsigned int	color;
	unsigned int	*pixels;
	SDL_Window		*win;
	SDL_Renderer	*rnd;
	SDL_Texture		*txt;
	SDL_Surface		*srf;
	SDL_Surface		*sky;
	SDL_Surface		*grnd;
	SDL_Surface		*walln;
	SDL_Surface		*walls;
	SDL_Surface		*walle;
	SDL_Surface		*wallw;
	SDL_Surface		*clt;
	t_key			key;
	SDL_Event		events;
}					t_sdl;

typedef struct		s_plr
{
	t_vec2			pos;
}					t_plr;

typedef struct		s_ray
{
	t_vec2			pos;
	float			angle;
	char			quarter;
}					t_ray;

typedef struct		s_wall
{
	float			dist;
	float			scaling;
	int				column;
	int				check_h;
	int				check_v;
	int				end;
	char			side;
	t_vec2			hit;
}					t_wall;

typedef struct		s_cam
{
	float			dist;
	float			ang;
	float			ang_u;
	float			ang_c[WIDTH];
}					t_cam;

typedef struct		s_spr
{
	char			check_h;
	char			check_v;
	int				cltd[WIDTH];
	int				wlld[WIDTH];
	int				cnt;
	unsigned int	clr_pnt;
}					t_spr;

typedef struct		s_pth
{
	char			map[25];
	char			tx[6][35];
}					t_pth;

typedef struct		s_frame
{
	t_sdl			sdl;
	t_pth			pth;
	t_cam			cam;
	t_plr			plr;
	t_ray			ray;
	t_wall			wall;
	t_spr			spr;
	unsigned char	map[1600];
}					t_frame;

void				error(t_frame *t, char *str);
void				read_arguments(t_frame *t, int ac, char **av);

void				sdl_init(t_sdl *sdl);
void				sdl_error(t_sdl *sdl, const char *error);
void				sdl_create_window(t_sdl *sdl);
void				sdl_create_surface(t_sdl *sdl);
void				sdl_put_surface(t_sdl *sdl);
void				sdl_cleaner(t_sdl *sdl);
void				start_casting(t_frame *t);
void				cast_ray(t_frame *t);
int					check_grid(t_frame *t, t_vec2 *v);
int					check_grid_tx(t_frame *t, t_vec2 *v);
int					check_grid_ty(t_frame *t, t_vec2 *v);
int					check_grid_bx(t_frame *t, t_vec2 *v);
int					check_grid_by(t_frame *t, t_vec2 *v);
void				trace_wall(t_frame *t);
void				distance_coloring(t_frame *t, int reduction);
float				horizontal_intersections(t_frame *t);
void				horizontal_updir(t_frame *t, t_vec2 *v, int n);
void				horizontal_downdir(t_frame *t, t_vec2 *v, int n);
float				vertical_intersections(t_frame *t);
void				vertical_rightdir(t_frame *t, t_vec2 *v, int n);
void				vertical_leftdir(t_frame *t, t_vec2 *v, int n);
void				check_sprite(t_frame *t, char dir);
void				put_sprites(t_frame *t);
void				sort_sprites(t_frame *t, int *dist, int *center);
int					center_sprites(int *dist, int *center, int *i);
void				put_points(t_frame *t);
void				update_points(t_frame *t);
void				remove_sprite(t_frame *t);

void				sdl_wait(t_frame *t);
int					sdl_exit(t_frame *t);
void				read_map(t_frame *t);
void				print_map(unsigned char *map);
void				protected_dif(float *angle, float dif);
void				protected_sum(float *angle, float sum);
void				generate_sky(t_frame *t);
void				draw_sky(t_frame *t);
void				draw_ground(t_frame *t);

#endif
