# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kibotrel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/26 14:18:48 by kibotrel          #+#    #+#              #
#    Updated: 2018/11/26 17:09:23 by kibotrel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fillit

SRCDIR		= srcs/
INCDIR		= ./includes/													\
			  ./libft/includes/

OBJDIR		= objs/
LIBDIR		= libft/

SRC			= main.c	parsing.c

INCPARAMS	= $(foreach d, $(INCDIR), -I$d)
CSRC		= $(addprefix $(SRCDIR), $(SRC))
COBJ		= $(addprefix $(OBJDIR), $(OBJ))
CHECKDIR	= $(shell if [ ! -d "$(OBJDIR)" ]; then	mkdir $(OBJDIR); fi)

OBJ			= $(SRC:.c=.o)
CFLAGS		= $(INCPARAMS) -Wall -Wextra -Werror
CC			= gcc

$(NAME): $(CHECKDIR) $(COBJ) mklib
	$(CC) -L $(LIBDIR) -lft $(CFLAGS) -o $(NAME) $(COBJ)

all: $(NAME)

mklib:
	make -C $(LIBDIR)

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: fillitclean libftclean

fclean: fillitfclean libftfclean

fillitclean:
	rm -rf $(COBJ)

fillitfclean: fillitclean
	rm -rf $(NAME)

libftclean:
	make clean -C $(LIBDIR)

libftfclean: libftclean
	make fclean -C $(LIBDIR)

re: fclean all

.PHONY: all clean fclean re mklib fillitclean fillitfclean libftclean libftfclean
