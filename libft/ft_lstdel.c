/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 13:17:11 by acouturi          #+#    #+#             */
/*   Updated: 2017/11/14 17:15:51 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *suiv;

	while (*alst)
	{
		del((*alst)->content, (*alst)->content_size);
		suiv = *alst;
		free(*alst);
		*alst = suiv->next;
	}
}
