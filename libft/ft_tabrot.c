/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabrot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <acouturi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 18:57:32 by acouturi          #+#    #+#             */
/*   Updated: 2018/01/31 20:37:03 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	**ft_tabrot(char **oldtab, int x, int y)
{
	char	**newtab;
	int		i;
	int		j;

	if (!(newtab = (char **)malloc(sizeof(char *) * y + 1)))
		return (0);
	newtab[y] = 0;
	j = -1;
	while (++j != y)
	{
		if (!(newtab[j] = (char *)malloc(x + 1)))
			return (0);
		newtab[j][x] = 0;
		i = -1;
		while (++i != x)
			newtab[j][i] = oldtab[i][j];
	}
	return (newtab);
}

char	**ft_tabrotfree(char **oldtab, int x, int y)
{
	char	**newtab;
	int		i;

	if (!(oldtab))
		return (0);
	newtab = ft_tabrot(oldtab, x, y);
	i = 0;
	while (oldtab[i])
		free(oldtab[i++]);
	free(oldtab);
	oldtab = 0;
	return (newtab);
}
