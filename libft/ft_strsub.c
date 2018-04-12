/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:33:45 by acouturi          #+#    #+#             */
/*   Updated: 2017/11/16 15:12:04 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*tab;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (NULL);
	tab = (char*)malloc(len + 1);
	if (!tab)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		tab[i] = s[start + i];
		i++;
	}
	tab[i] = 0;
	return (tab);
}
