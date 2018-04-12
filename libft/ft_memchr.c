/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:11:35 by acouturi          #+#    #+#             */
/*   Updated: 2017/11/18 15:35:54 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *str;

	str = (unsigned char *)s;
	while (n-- > 0)
		if (*str++ == (unsigned char)c)
		{
			str--;
			return (str);
		}
	return (0);
}
