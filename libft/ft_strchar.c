/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <acouturi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 20:33:38 by acouturi          #+#    #+#             */
/*   Updated: 2018/01/31 18:09:16 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_strchar(const char *source, const char *list)
{
	int		i;
	int		j;

	i = 0;
	if (list[0] == '\0')
		return (0);
	while (source[i])
	{
		j = 0;
		while (list[j])
			if (source[i] == list[j++])
				return (source[i]);
		i++;
	}
	return (0);
}
