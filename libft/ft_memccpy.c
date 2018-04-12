/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:12:39 by acouturi          #+#    #+#             */
/*   Updated: 2017/11/16 15:09:03 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*dest;
	char	*source;

	dest = (char *)dst;
	source = (char *)src;
	while (0 < n--)
	{
		*dest++ = *source;
		if (*source++ == (char)c)
			return (dest);
	}
	return (NULL);
}
