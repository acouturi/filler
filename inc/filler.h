/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <acouturi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:33:31 by acouturi          #+#    #+#             */
/*   Updated: 2018/02/14 15:26:32 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <stdint.h>
# include <stdarg.h>
# include <errno.h>
# include <assert.h>
# include <wchar.h>
# include <inttypes.h>

typedef struct	s_piece
{
	int			x;
	int			y;
	float		o_x;
	float		o_y;
	int			touche;
	uintmax_t	dist;
	int			decal_x;
	int			decal_y;
	char		**forme;
}				t_piece;

typedef struct	s_xy
{
	int			x;
	int			y;
}				t_xy;

typedef struct	s_map
{
	int			my_num;
	char		my_form;
	char		it_form;
	int			my_x;
	int			my_y;
	int			it_x;
	int			it_y;
	int			it_change_x;
	int			it_change_y;
	int			map_x;
	int			map_y;
	t_piece		*piece;
	char		**grille;
	char		**oldgrille;
}				t_map;

void			howplayer(t_map *map);
void			ft_debug(t_map *map);
char			**rempgrille(char *line, t_map *map);
t_piece			*remppiece(char *line);
void			ft_recup(t_map *map);
t_map			*ft_init(void);
void			ft_place(t_map *map);

#endif
