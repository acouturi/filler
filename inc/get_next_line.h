/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 12:58:39 by acouturi          #+#    #+#             */
/*   Updated: 2017/11/28 14:47:47 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32

typedef struct	s_file
{
	char			*memstr;
	char			*start;
	int				fd;
	struct s_file	*next;
}				t_file;

int				get_next_line(const int fd, char **line);

#endif
