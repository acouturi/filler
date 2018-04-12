/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:55:58 by acouturi          #+#    #+#             */
/*   Updated: 2017/11/10 13:26:41 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int		i;
	int		mem;

	i = 0;
	while (dest[i])
		i++;
	mem = 0;
	while (src[mem])
	{
		dest[i + mem] = src[mem];
		mem++;
	}
	dest[i + mem] = 0;
	return (dest);
}
