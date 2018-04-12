/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:48:30 by acouturi          #+#    #+#             */
/*   Updated: 2017/11/16 15:09:50 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char *s1;
	char *s2;

	s1 = (char*)dest;
	s2 = (char*)src;
	if (dest <= src)
		return (ft_memcpy(dest, src, n));
	while (n-- > 0)
		s1[n] = s2[n];
	return (dest);
}
