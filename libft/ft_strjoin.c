/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:54:05 by acouturi          #+#    #+#             */
/*   Updated: 2017/11/25 18:47:17 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*tab;
	int		len1;
	int		len2;
	int		i;

	if (!s1 || !s2)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	tab = (char*)malloc(len1 + len2 + 1);
	if (!tab)
		return (0);
	i = -1;
	while (++i < len1)
		tab[i] = s1[i];
	i = 0;
	while (i < len2)
	{
		tab[i + len1] = s2[i];
		i++;
	}
	tab[i + len1] = 0;
	return (tab);
}
