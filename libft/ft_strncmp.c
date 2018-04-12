/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:15:07 by acouturi          #+#    #+#             */
/*   Updated: 2017/11/18 17:05:17 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			ici;
	unsigned char	*un;
	unsigned char	*deux;

	if (!n)
		return (0);
	un = (unsigned char *)s1;
	deux = (unsigned char *)s2;
	ici = 0;
	while ((un[ici] != 0 || deux[ici] != 0) && n > ici)
	{
		if (un[ici] != deux[ici])
			return (un[ici] - deux[ici]);
		ici++;
	}
	return (0);
}
