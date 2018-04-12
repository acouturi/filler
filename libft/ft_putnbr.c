/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:05:50 by acouturi          #+#    #+#             */
/*   Updated: 2017/11/15 15:36:08 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int	tmp;

	if (n < 0)
	{
		ft_putchar('-');
		tmp = -n;
	}
	else
		tmp = n;
	if (tmp / 10)
		ft_putnbr(tmp / 10);
	ft_putchar('0' + tmp % 10);
}
