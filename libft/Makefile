# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acouturi <acouturi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 14:51:13 by acouturi          #+#    #+#              #
#    Updated: 2018/02/01 15:53:52 by acouturi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
	  ft_isprint.c ft_putchar.c ft_putendl.c ft_putstr.c ft_strchr.c \
	  ft_strlen.c ft_tolower.c ft_toupper.c ft_strequ.c ft_strnequ.c \
	  ft_strrchr.c ft_strcmp.c ft_strncmp.c ft_strstr.c ft_strnstr.c \
	  ft_strclr.c ft_striter.c ft_striteri.c ft_strdel.c ft_strdel.c \
	  ft_putnbr.c ft_itoa.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	  ft_putnbr_fd.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c \
	  ft_strncat.c ft_strlcat.c ft_memalloc.c ft_bzero.c ft_memset.c \
	  ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
	  ft_memdel.c ft_strnew.c ft_strmap.c ft_strmapi.c ft_strsub.c \
	  ft_strjoin.c ft_strsplit.c ft_strtrim.c ft_lstnew.c ft_lstdelone.c \
	  ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_pwd.c \
	  ft_lstaddend.c ft_strrev.c ft_puterror.c ft_isupper.c ft_islower.c \
	  ft_tabrot.c ft_strchar.c ft_abs.c

# Colors
_GREY	= "\033[0;30m"
_RED	= "\033[0;31m"
_GREEN	= "\033[0;32m"
_YELLOW	= "\033[0;33m"
_BLUE	= "\033[0;34m"
_PURPLE	= "\033[0;35m"
_CYAN	= "\033[0;36m"
_WHITE	= "\033[0;37m"
_NONE	= "\033[0m"

OBJ = $(SRC:.c=.o)

INCL = -I.

CFLAGS = -Werror -Wall -Wextra

all : $(NAME)

$(NAME) : $(OBJ)
	@ar rcs $(NAME) $^
	@echo $(_YELLOW) "Created :	" $(_NONE) $(NAME)
	@echo $(_GREEN) "DONE"

%.o : %.c
	@gcc $(CFLAGS) -o $@ -c $<
	@echo $(_YELLOW) "Compiling :	" $(_NONE) $<

clean:
	@echo $(_RED) "Remove :" $(OBJ)
	@/bin/rm -f $(OBJ)
	@echo $(_GREEN) "DONE"

fclean: clean
	@echo $(_RED) "Remove :" $(NAME)
	@/bin/rm -f $(NAME)
	@echo $(_GREEN) "DONE"

re: fclean all

exe: all clean
