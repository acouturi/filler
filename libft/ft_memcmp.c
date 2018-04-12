/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:03:34 by acouturi          #+#    #+#             */
/*   Updated: 2017/11/15 10:39:17 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*un;
	unsigned char	*deux;

	un = (unsigned char *)s1;
	deux = (unsigned char *)s2;
	if (!n)
		return (0);
	i = 0;
	while (un[i] == deux[i] && 1 < n--)
		i++;
	return (un[i] - deux[i]);
}
