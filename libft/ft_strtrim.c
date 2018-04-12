/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:08:29 by acouturi          #+#    #+#             */
/*   Updated: 2017/11/16 15:12:52 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*ft_remp(char *s, char *str, int start, int len)
{
	int		i;

	i = 0;
	while (i < len && s[start])
		str[i++] = s[start++];
	str[len] = 0;
	return (str);
}

char		*ft_strtrim(const char *s)
{
	int		len;
	char	*str;
	int		i;
	int		start;

	len = 0;
	i = 0;
	start = 0;
	if (!s)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		start = ++i;
	if (s[i] != 0)
	{
		while (s[i++])
			len++;
		i -= 2;
		while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && i-- >= 0)
			len--;
	}
	if (!(str = (char*)malloc(len + 1)))
		return (NULL);
	ft_remp((char *)s, str, start, len);
	return (str);
}
