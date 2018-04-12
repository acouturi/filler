/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <acouturi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 15:14:57 by acouturi          #+#    #+#             */
/*   Updated: 2018/02/14 14:08:18 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../inc/get_next_line.h"
#include "../inc/filler.h"

static void		ft_traitplateau(t_map *map, char *line)
{
	int	i;
	int	j;

	map->grille = rempgrille(line, map);
	i = 0;
	while (i < map->map_x)
	{
		j = 0;
		while (j < map->map_y)
		{
			if (map->oldgrille[i][j] != map->grille[i][j])
			{
				map->it_change_x = i;
				map->it_change_y = j;
			}
			j++;
		}
		ft_strcpy(map->oldgrille[i], map->grille[i]);
		i++;
	}
}

static void		ft_loop(t_map *map)
{
	char	*line;
	int		i;

	line = 0;
	while ((get_next_line(0, &line) == 1))
	{
		if (ft_strncmp(line, "Plateau", 7) == 0)
			ft_traitplateau(map, line);
		else if (ft_strncmp(line, "Piece", 5) == 0)
		{
			if (map->piece)
			{
				i = 0;
				while (map->piece->forme[i])
					free(map->piece->forme[i++]);
				free(map->piece->forme);
				free(map->piece);
			}
			map->piece = remppiece(line);
			ft_place(map);
		}
		free(line);
	}
	return ;
}

static void		ft_end(t_map *map)
{
	int		i;

	if (map->grille)
	{
		i = 0;
		while (map->grille[i])
			free(map->grille[i++]);
		free(map->grille);
	}
	if (map->oldgrille)
	{
		i = 0;
		while (map->oldgrille[i])
			free(map->oldgrille[i++]);
		free(map->oldgrille);
	}
	if (map->piece)
	{
		i = 0;
		while (map->piece->forme[i])
			free(map->piece->forme[i++]);
		free(map->piece->forme);
		free(map->piece);
	}
	free(map);
}

int				main(void)
{
	t_map	*map;

	map = ft_init();
	if (map)
		ft_loop(map);
	if (map)
		ft_end(map);
	return (0);
}
