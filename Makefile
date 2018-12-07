# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abaurens <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/27 16:23:33 by abaurens          #+#    #+#              #
#    Updated: 2018/12/07 15:01:22 by kibotrel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Executable's name (Can be changed)

NAME		= fillit

# All the directories needed to know where files should be (Can be changed)

OBJDIR		= objs/
SRCDIR		= srcs/
INCDIR		= ./includes/

# Source files (Can be changed)

SRC			= process.c			\
			  post_parse.c		\
			  post_process.c	\
			  check_grid.c		\
			  parsing.c			\
			  utils.c

# Some tricks in order to get the makefile doing his job the way I want (Can't be changed)

CSRC		= $(addprefix $(SRCDIR), $(SRC))
COBJ		= $(addprefix $(OBJDIR), $(OBJ))
CHECKDIR	= $(shell if [ ! -d "$(OBJDIR)" ]; then	mkdir $(OBJDIR); fi)

# How files should be compiled with set flags (Can be changed)

OBJ			= $(SRC:.c=.o)
CFLAGS		= -I$(INCDIR) -Wall -Wextra -Werror
CC			= gcc

$(NAME): $(CHECKDIR) $(COBJ)
	@echo "\033[33m\n      - Building \033[0m$(NAME) \033[33m...\n\033[0m"
	@gcc -o $(NAME) $(COBJ)
	@echo "\033[32m***   Project $(NAME) successfully compiled   ***\n\033[0m"

all: $(NAME)

# Redefinition of implicit compilation rule to prompt some colors and file names during the said compilation

$(OBJDIR)%.o: $(SRCDIR)%.c
	@echo "\033[33m      - Compiling :\033[0m" $<
	@$(CC) $(CFLAGS) -c $< -o $@

# Deleting all .o files and then the directory where they were located

clean:
	@clear
	@echo "\033[32m***   Deleting all object files   ...   ***\n\033[0m"
	@rm -rf $(COBJ)

# Deleting the binary after cleaning up all .o files

fclean:	clean
	@echo "\033[32m***   Deleting executable file    ...   ***\n\033[0m"
	@rm -rf $(NAME)

re:	fclean all

.PHONY: all clean fclean re
