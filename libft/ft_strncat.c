/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:07:31 by acouturi          #+#    #+#             */
/*   Updated: 2017/11/10 13:25:08 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	int		i;
	size_t	mem;

	i = 0;
	while (dest[i])
		i++;
	mem = 0;
	while (src[mem] && mem < n)
	{
		dest[i + mem] = src[mem];
		mem++;
	}
	dest[i + mem++] = 0;
	return (dest);
}
