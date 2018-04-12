/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <acouturi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 13:03:13 by acouturi          #+#    #+#             */
/*   Updated: 2018/02/14 16:57:14 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../inc/get_next_line.h"
#include "../inc/filler.h"

static intmax_t	ft_tryplace(t_map *map, int dec_x, int dec_y)
{
	intmax_t	ok;
	int			loop;
	int			x;
	int			y;

	ok = map->piece->x * map->piece->y;
	loop = 1;
	x = -1;
	while (++x < map->piece->x)
	{
		y = -1;
		while (++y < map->piece->y)
		{
			if (map->piece->forme[x][y] == '.' ||
			map->grille[dec_x + x][dec_y + y] == '.')
				ok--;
			else if (map->grille[dec_x + x][dec_y + y] == map->my_form &&
			loop-- == 1)
				ok--;
			else
				return (-1);
		}
	}
	return (loop == 0 ? ok : -1);
}

static intmax_t	ft_cmpt2(t_map *map, int dec_x, int dec_y, t_xy xy)
{
	intmax_t	nbp;

	nbp = 0;
	if (xy.x == 0 && dec_x != 0)
		nbp += map->grille[dec_x - 1][dec_y + xy.y] == map->it_form ? 2 : 0;
	else if (xy.x == 0 && dec_x == 0)
		nbp++;
	if (xy.x == map->piece->x - 1 && dec_x + xy.x < map->map_x - 1)
		nbp += map->grille[dec_x + xy.x + 1][dec_y + xy.y]
		== map->it_form ? 2 : 0;
	else if (xy.x == map->piece->x - 1 && dec_x + xy.x == map->map_x - 1)
		nbp++;
	if (xy.y == 0 && dec_y != 0)
		nbp += map->grille[dec_x + xy.x][dec_y - 1] == map->it_form ? 2 : 0;
	else if (xy.y == 0 && dec_y == 0)
		nbp++;
	if (xy.y == map->piece->y - 1 && dec_y + xy.y < map->map_y - 1)
		nbp += map->grille[dec_x + xy.x][dec_y + xy.y + 1]
		== map->it_form ? 2 : 0;
	else if (xy.y == map->piece->y - 1 && dec_y + xy.y == map->map_y - 1)
		nbp++;
	return (nbp);
}

static intmax_t	ft_cmpt(t_map *map, int dec_x, int dec_y)
{
	intmax_t	nbpiece;
	t_xy		xy;

	xy.x = 0;
	nbpiece = 0;
	while (xy.x < map->piece->x)
	{
		xy.y = 0;
		while (xy.y < map->piece->y)
		{
			if (map->piece->forme[xy.x][xy.y] != '.')
			{
				nbpiece += ft_cmpt2(map, dec_x, dec_y, xy);
			}
			else if (map->grille[dec_x + xy.x][dec_y + xy.y] == map->it_form)
				nbpiece += 8;
			xy.y++;
		}
		xy.x++;
	}
	return (nbpiece);
	dec_x = dec_y;
}

void			ft_ifplace(t_map *map, int i, int j, t_xy *xy)
{
	intmax_t	tmp;

	if ((tmp = ft_cmpt(map, i, j)) > map->piece->touche)
	{
		map->piece->touche = tmp;
		xy->x = i;
		xy->y = j;
	}
	else if (map->piece->touche == 0)
	{
		tmp = (ft_pwd(ft_abs(map->it_x - i), 2) +
				ft_pwd(ft_abs(map->it_y - j), 2));
		if ((uintmax_t)tmp < map->piece->dist)
		{
			map->piece->dist = tmp;
			xy->x = i;
			xy->y = j;
		}
	}
}

void			ft_place(t_map *map)
{
	int			i;
	int			j;
	t_xy		xy;

	xy.x = 0;
	xy.y = 0;
	map->piece->touche = 0;
	map->piece->dist = -1;
	i = -1;
	while (++i < map->map_x - map->piece->x + 1)
	{
		j = -1;
		while (++j < map->map_y - map->piece->y + 1)
		{
			if (ft_tryplace(map, i, j) == 0)
			{
				ft_ifplace(map, i, j, &xy);
			}
		}
	}
	ft_putnbr(xy.x - map->piece->decal_x);
	ft_putchar(' ');
	ft_putnbr(xy.y - map->piece->decal_y);
	ft_putchar('\n');
}
