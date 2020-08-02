/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 21:53:20 by gbianco           #+#    #+#             */
/*   Updated: 2020/02/04 18:17:30 by gbianco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_H
# define VEC_H

# include <math.h>

typedef struct	s_vec2
{
	double		x;
	double		y;
}				t_vec2;

typedef	struct	s_vec3i
{
	int i;
	int	j;
	int k;
}				t_vec3i;

typedef	struct	s_vec3
{
	double		x;
	double		y;
	double		z;
}				t_vec3;

typedef	struct	s_vec4
{
	double		x;
	double		y;
	double		z;
	double		w;
}				t_vec4;

double			v2_dot(t_vec2 v1, t_vec2 v2);
double			v2_len(t_vec2 v1, t_vec2 v2);
double			v2_le2(t_vec2 v1, t_vec2 v2);
t_vec2			v2(double x, double y);
t_vec2			v2_dif(t_vec2 v1, t_vec2 v2);
int				v3_cmp(t_vec3 v1, t_vec3 v2);
double			v3_dot(t_vec3 v1, t_vec3 v2);
double			v3_len(t_vec3 v1, t_vec3 v2);
double			v3_le2(t_vec3 v1, t_vec3 v2);
t_vec3			mtov(double m[4][1]);
t_vec3			v3(double x, double y, double z);
t_vec3			v3_add(t_vec3 v1, t_vec3 v2);
t_vec3			v3_dif(t_vec3 v1, t_vec3 v2);
t_vec3			v3_pro(t_vec3 v1, t_vec3 v2);
t_vec3			v3_div(t_vec3 v1, t_vec3 v2);
t_vec3			v3_ver(t_vec3 v1, t_vec3 v2);
t_vec3			v3_nor(t_vec3 v1);
t_vec3			v3_snr(t_vec3 v1);
t_vec3			v3_scp(t_vec3 v1, double d);
t_vec3			v3_scd(t_vec3 v1, double d);
t_vec3			v3_cro(t_vec3 v1, t_vec3 v2);
t_vec3			v3_neg(t_vec3 v1);
double			v4_len(t_vec4 q);
t_vec4			v4(double x, double y, double z, double w);
t_vec4			v4_dot(t_vec4 q1, t_vec4 q2);
t_vec4			v4_nor(t_vec4 q);
t_vec4			v4_con(t_vec4 q);

#endif
