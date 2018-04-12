/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:06:20 by acouturi          #+#    #+#             */
/*   Updated: 2017/11/14 18:46:48 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddend(t_list **alst, t_list *newele)
{
	t_list	*tmp;

	if (!*alst)
		*alst = newele;
	else
	{
		tmp = *alst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = newele;
	}
}
