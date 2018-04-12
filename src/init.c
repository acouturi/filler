/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <acouturi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 16:02:25 by acouturi          #+#    #+#             */
/*   Updated: 2018/02/06 21:10:30 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../inc/get_next_line.h"
#include "../inc/filler.h"

void			howplayer(t_map *map)
{
	char	*line;
	char	*start;

	get_next_line(0, &line);
	start = line;
	while (*line != 'p')
		line++;
	line++;
	map->my_num = *line - '0';
	map->my_form = map->my_num == 1 ? 'O' : 'X';
	map->it_form = map->my_num == 1 ? 'X' : 'O';
	free(start);
}

static t_map	*ft_suite(t_map *map, char *line, char *start)
{
	int		i;

	i = 0;
	while (i < map->map_x)
	{
		if (!(map->oldgrille[i] = (char *)malloc(map->map_y + 1)))
			return (0);
		ft_bzero(map->oldgrille[i++], map->map_y + 1);
	}
	i = 0;
	while (i < map->map_x)
	{
		ft_strcpy(map->oldgrille[i], map->grille[i]);
		i++;
	}
	get_next_line(0, &line);
	start = line;
	map->piece = remppiece(line);
	free(start);
	ft_place(map);
	return (map);
}

t_map			*ft_init(void)
{
	t_map		*map;
	char		*line;
	char		*start;

	if ((map = (t_map *)malloc(sizeof(t_map))) == 0)
		return (0);
	ft_bzero(map, sizeof(t_map));
	howplayer(map);
	get_next_line(0, &line);
	start = line;
	map->grille = rempgrille(line, map);
	free(start);
	ft_recup(map);
	if (!(map->oldgrille = (char **)malloc(sizeof(char *) * map->map_x + 1)))
		return (0);
	map->oldgrille[map->map_x] = NULL;
	return (ft_suite(map, line, start));
}
