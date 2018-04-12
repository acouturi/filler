/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recupinfo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <acouturi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 18:47:24 by acouturi          #+#    #+#             */
/*   Updated: 2018/02/06 20:24:24 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../inc/get_next_line.h"
#include "../inc/filler.h"

void		ft_recup(t_map *map)
{
	int j;
	int i;

	i = 0;
	j = 0;
	while (map->grille[i])
	{
		if (map->grille[i][j] != '.')
		{
			if (map->grille[i][j] == map->my_form)
			{
				map->my_x = i;
				map->my_y = j;
			}
			else if (map->grille[i][j] == map->it_form)
			{
				map->it_x = i;
				map->it_y = j;
			}
		}
		j++;
		if (!map->grille[i][j] && (j = 0) + 1)
			i++;
	}
}
