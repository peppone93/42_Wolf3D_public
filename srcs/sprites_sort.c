/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbianco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 14:39:27 by gbianco           #+#    #+#             */
/*   Updated: 2020/08/02 14:39:29 by gbianco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	sort_sprites_b(int *dist, int *center)
{
	int i;
	int j;
	int temp[2];

	j = -1;
	while (dist[++j] != -1)
	{
		i = -1;
		while (dist[++i] != -1)
		{
			if (i > 0 && dist[i] > dist[i - 1])
			{
				temp[0] = dist[i];
				temp[1] = center[i];
				dist[i] = dist[i - 1];
				center[i] = center[i - 1];
				dist[i - 1] = temp[0];
				center[i - 1] = temp[1];
			}
		}
	}
}

void	sort_sprites(t_frame *t, int *dist, int *center)
{
	int i;
	int count;

	count = 0;
	i = -1;
	while (++i < WIDTH)
	{
		if (t->spr.cltd[i] != -1)
		{
			dist[count] = t->spr.cltd[i];
			center[count] = i;
			count++;
		}
	}
	dist[count] = -1;
	center[count] = -1;
	sort_sprites_b(dist, center);
}

int		center_sprites(int *dist, int *center, int *i)
{
	int sum;
	int count;
	int dif;

	sum = 0;
	count = 0;
	while (dist[*i] != -1)
	{
		dif = abs(dist[*i] - dist[*i + 1]);
		if (dif > 2 || (dif == 0 && (abs(center[*i] - center[*i + 1]) > 1)))
			break ;
		sum += center[*i];
		count++;
		(*i)++;
	}
	if (dist[*i] != -1)
	{
		sum += center[*i];
		count++;
	}
	sum /= count;
	return (sum);
}
