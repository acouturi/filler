/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:47:09 by acouturi          #+#    #+#             */
/*   Updated: 2017/11/16 15:13:16 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_cmpt(char *s, char c)
{
	int i;
	int len;

	len = 0;
	if (s[0] != c && s[0])
		len++;
	i = 1;
	while (s[i])
	{
		if (s[i - 1] == c && s[i] != c)
			len++;
		i++;
	}
	return (len);
}

static int		ft_nbchar(char *s, char c)
{
	int		ret;

	ret = 0;
	while (*s != c && *s++)
		ret++;
	return (ret);
}

char			**ft_strsplit(const char *s, char c)
{
	char	**tab;
	int		i;
	int		k;

	if (!s)
		return (0);
	tab = (char**)malloc(sizeof(char*) * (ft_cmpt((char*)s, c) + 1));
	if (!tab)
		return (0);
	i = 0;
	while (*s)
	{
		k = 0;
		while (*s == c)
			s++;
		if (!(*s))
			break ;
		tab[i] = (char*)malloc(ft_nbchar((char*)s, c) + 1);
		while (*s != c && *s)
			tab[i][k++] = *s++;
		tab[i++][k] = 0;
	}
	tab[i] = 0;
	return (tab);
}
