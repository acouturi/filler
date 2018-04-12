/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:17:26 by acouturi          #+#    #+#             */
/*   Updated: 2017/11/09 19:24:00 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *source, const char *mot)
{
	int		i;
	int		mem;

	i = 0;
	if (mot[0] == '\0')
		return ((char *)source);
	while (source[i])
	{
		mem = 0;
		while (source[i + mem] == mot[mem])
		{
			mem++;
			if (mot[mem] == 0)
				return ((char *)&source[i]);
		}
		i++;
	}
	return (0);
}
