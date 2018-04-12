# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acouturi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 14:51:13 by acouturi          #+#    #+#              #
#    Updated: 2018/02/06 21:17:21 by acouturi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = acouturi.filler

SRC_DIR = ./src/

SRC_NAME = get_next_line.c	init.c		lireinfo.c	placement.c	\
		   recupinfo.c		main.c

SRC = $(addprefix $(SRC_DIR),$(SRC_NAME))

LIBFT = libft/libft.a

OBJ_DIR = ./obj/
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_DIR),$(OBJ_NAME))

INCL = -I.

CFLAGS = -Werror -Wall -Wextra

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

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C libft
	@echo $(_BLUE) "Created :	" $(_NONE) $(NAME)
	@gcc $(CFLAGS) -o $(NAME) $(SRC) $(LIBFT)
	@echo $(_GREEN) "DONE"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@echo $(_BLUE) "Compiling :	" $(_NONE) $<
	@gcc $(CFLAGS) -o $@ -c $<

clean: cleano
	@make clean -C libft

cleano :
	@echo $(_RED) "Remove :" $(OBJ_DIR) $(_NONE)
	@/bin/rm -rf $(OBJ_DIR)
	@echo $(_GREEN) "DONE" $(_NONE)

fclean: cleano
	@make fclean -C libft
	@echo $(_RED) "Remove :" $(NAME) $(_NONE)
	@/bin/rm -f $(NAME)
	@echo $(_GREEN) "DONE" $(_NONE)

re: fclean all

exe: all clean
