/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 21:01:02 by acouturi          #+#    #+#             */
/*   Updated: 2017/11/16 15:13:57 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

t_list	*ft_lstnew(const void *content, size_t content_size)
{
	t_list	*start;

	if (!(start = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!(start->content = (void*)malloc(content_size)))
		return (NULL);
	if (!content)
	{
		start->content = NULL;
		start->content_size = 0;
	}
	else
	{
		ft_memcpy(start->content, (void*)content, content_size);
		start->content_size = content_size;
	}
	start->next = NULL;
	return (start);
}
