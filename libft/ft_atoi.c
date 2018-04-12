/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:10:31 by acouturi          #+#    #+#             */
/*   Updated: 2017/11/15 10:36:01 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *nptr)
{
	int		i;
	long	result;
	int		signe;

	i = 0;
	while (nptr[i] == '\t' || nptr[i] == '\v' || nptr[i] == '\f' ||
			nptr[i] == '\r' || nptr[i] == '\n' || nptr[i] == ' ' ||
			nptr[i] == '\f')
		i++;
	signe = 1;
	if (nptr[i] == '-')
		signe = -1;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	result = 0;
	while (ft_isdigit(nptr[i]) == 1)
	{
		result = result * 10 + nptr[i++] - '0';
		if (result < 0)
			return (signe > 0 ? -1 : 0);
	}
	return (result * signe);
}
