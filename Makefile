# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/04 13:03:16 by pbourdon          #+#    #+#              #
#    Updated: 2016/11/08 16:52:07 by pbourdon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


ifeq ($(HOSTTYPETYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

LIBPATH = ./libft/
LIB = $(LIBPATH)/malloc.a

NAME = malloc

CC = @gcc
## -Wall -Werror -Wextra

## SO = gcc -o libft_malloc_$(HOSTTYPE).so -shared

CFLAGS =

LDFLAGS = -L $(LIBPATH) -lft

SRC =	main.c\
		

OBJ = $(SRC:.c=.o)

all: $(LIB) $(NAME)

$(NAME):	$(OBJ)
	@$(CC) $(LDFLAGS) -o $@ $^
##	@$(SO) $(OBJ)
##	@ln -s libft_malloc_$(HOSTTYPE).so libft_malloc.so

$(LIB):
	@make -C $(LIBPATH)

clean:
	@echo "cleaning object files"
	@rm -f $(OBJ)
	@make clean -C $(LIBPATH)

fclean: clean
	@rm -f $(NAME)
	@rm -rf libft_malloc_$(HOSTTYPE).so
	@rm -rf libft_malloc.so
	@make fclean -C $(LIBPATH)

re: fclean all

.PHONY: all re clean flcean
