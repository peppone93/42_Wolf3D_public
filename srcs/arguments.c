/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbianco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 12:39:29 by gbianco           #+#    #+#             */
/*   Updated: 2020/08/02 17:12:34 by gbianco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	txt_assigner_children_a(t_frame *t)
{
	char	*tx[6];
	int		i;
	int		j;

	tx[0] = "/Ground.bmp";
	tx[1] = "/North.bmp";
	tx[2] = "/South.bmp";
	tx[3] = "/Est.bmp";
	tx[4] = "/West.bmp";
	tx[5] = "/Collect.bmp";
	i = -1;
	while (++i < 6)
	{
		j = 0;
		while (tx[i][j] != '\0')
		{
			t->pth.tx[i][j + 19] = tx[i][j];
			j++;
		}
		t->pth.tx[i][j + 19] = '\0';
	}
}

void	txt_assigner_children_b(t_frame *t, char x)
{
	int c;

	c = x - 48;
	if (c == 1)
		t->sdl.color = VIOLET;
	else if (c == 2)
		t->sdl.color = GREY;
	else if (c == 3)
		t->sdl.color = GREEN;
}

void	txt_assigner(t_frame *t, char x)
{
	char	*path;
	int		i;
	int		j;

	path = "./Images/Textures/";
	i = -1;
	while (++i < 6)
	{
		j = 0;
		while (path[j] != '\0')
		{
			t->pth.tx[i][j] = path[j];
			j++;
		}
		t->pth.tx[i][j] = x;
	}
	txt_assigner_children_a(t);
	txt_assigner_children_b(t, x);
}

void	map_assigner(t_frame *t, char *str)
{
	char	*path;
	char	*exts;
	int		i;
	int		j;

	path = "./Images/Maps/";
	exts = ".bmp";
	i = -1;
	while (path[++i] != '\0')
		t->pth.map[i] = path[i];
	j = -1;
	while (str[++j] != '\0')
		t->pth.map[i + j] = str[j];
	i = i + j;
	j = -1;
	while (exts[++j] != '\0')
		t->pth.map[i + j] = exts[j];
	t->pth.map[i + j] = '\0';
}

void	read_arguments(t_frame *t, int ac, char **av)
{
	int i;

	if (ac != 3)
		error(t, "Usage: ./wolf3d [map] [texturepack]");
	i = -1;
	while (av[1][++i])
		if (ft_isdigit(av[1][i]) == 0)
			error(t, "Invalid map [1 to 99]");
	if (i > 2)
		error(t, "Invalid map [1 to 99]");
	if (ft_isdigit(av[2][0]) == 0)
		error(t, "Invalid texture pack [1 to 3]");
	map_assigner(t, av[1]);
	txt_assigner(t, av[2][0]);
}
