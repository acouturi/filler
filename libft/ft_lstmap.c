/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:51:30 by acouturi          #+#    #+#             */
/*   Updated: 2017/11/15 13:39:07 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *start;
	t_list *current;
	t_list *mem;

	if (!lst)
		return (NULL);
	mem = f(lst);
	start = mem;
	current = lst->next;
	while (current)
	{
		mem->next = f(current);
		mem = mem->next;
		current = current->next;
	}
	return (start);
}
