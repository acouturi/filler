/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:15:07 by acouturi          #+#    #+#             */
/*   Updated: 2017/11/16 14:59:43 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	int				ici;
	unsigned char	*un;
	unsigned char	*deux;

	un = (unsigned char *)s1;
	deux = (unsigned char *)s2;
	ici = 0;
	while (un[ici] != 0 || deux[ici] != 0)
	{
		if (un[ici] != deux[ici])
			return (un[ici] - deux[ici]);
		ici++;
	}
	return (0);
}
