/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lireinfo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <acouturi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 16:53:18 by acouturi          #+#    #+#             */
/*   Updated: 2018/02/14 14:22:21 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../inc/get_next_line.h"
#include "../inc/filler.h"

#define IFRET(x, y) if (x) return (y)

static void		decodeline(char *line, int *x, int *y)
{
	while (*line != ' ')
		line++;
	line++;
	*x = ft_atoi(line);
	while (*line != ' ')
		line++;
	line++;
	*y = ft_atoi(line);
}

char			**rempgrille(char *line, t_map *map)
{
	static char	**grille = 0;
	int			i;
	char		*start;

	decodeline(line, &map->map_x, &map->map_y);
	if (!(grille))
	{
		IFRET(!(grille = (char **)malloc(sizeof(char *) * map->map_x + 1)), 0);
		ft_bzero(grille, sizeof(char *) * map->map_x + 1);
	}
	grille[map->map_x] = 0;
	i = 0;
	get_next_line(0, &line);
	while (map->map_x != i && get_next_line(0, &line) == 1)
	{
		IFRET(!grille[i] &&
		!(grille[i] = (char *)malloc(sizeof(char) * map->map_y + 1)), 0);
		start = line;
		while (*line == ' ' || ft_isdigit(*line))
			line++;
		grille[i][0] = 0;
		ft_strcpy(grille[i++], line);
		free(start);
	}
	return (grille);
}

t_piece			*smppiecerot(t_piece *piece)
{
	int		i;

	i = 0;
	while (piece->forme[i] && ft_strchar(piece->forme[i], "*") == 0 && ++i)
		piece->decal_y++;
	i = piece->y - 1;
	while (piece->forme[i] && ft_strchar(piece->forme[i], "*") == 0 && i--)
		piece->y--;
	piece->y -= piece->decal_y;
	i = -1;
	while (++i < piece->y)
		ft_strcpy(piece->forme[i], piece->forme[i + piece->decal_y]);
	--i;
	while (piece->forme[++i])
		ft_memset(piece->forme[i], 0, ft_strlen(piece->forme[i]));
	piece->forme = ft_tabrotfree(piece->forme, piece->y, piece->x);
	return (piece);
}

t_piece			*smppiece(t_piece *piece)
{
	int		i;

	i = 0;
	piece->decal_x = 0;
	piece->decal_y = 0;
	while (piece->forme[i] && ft_strchar(piece->forme[i], "*") == 0 && ++i)
		piece->decal_x++;
	i = piece->x - 1;
	while (piece->forme[i] && ft_strchar(piece->forme[i], "*") == 0 && i--)
		piece->x--;
	piece->x -= piece->decal_x;
	i = -1;
	while (++i < piece->x)
		ft_strcpy(piece->forme[i], piece->forme[i + piece->decal_x]);
	--i;
	while (piece->forme[++i])
		ft_memset(piece->forme[i], 0, ft_strlen(piece->forme[i]));
	piece->forme = ft_tabrotfree(piece->forme, piece->x, piece->y);
	return (smppiecerot(piece));
}

t_piece			*remppiece(char *line)
{
	t_piece	*piece;
	int		i;

	if ((piece = (t_piece *)malloc(sizeof(t_piece))) == 0)
		return (0);
	decodeline(line, &piece->x, &piece->y);
	if ((piece->forme = (char **)malloc(sizeof(char *) * piece->x + 1)) == 0)
		return (0);
	i = 0;
	while (piece->x != i)
	{
		get_next_line(0, &line);
		piece->forme[i] = line;
		i++;
	}
	piece->forme[piece->x] = NULL;
	i = 0;
	piece = smppiece(piece);
	piece->o_x = (float)piece->x / 2 - 0.5;
	piece->o_y = (float)piece->y / 2 - 0.5;
	return (piece);
}
