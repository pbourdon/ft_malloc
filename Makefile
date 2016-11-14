# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/04 13:03:16 by pbourdon          #+#    #+#              #
#    Updated: 2016/11/14 17:16:37 by pbourdon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

LIBPATH = ./libft/
LIB = $(LIBPATH)/malloc.a

NAME = malloc

CC = @gcc -Wall -Werror -Wextra

SO = gcc -o libft_malloc_$(HOSTTYPE).so -shared

CFLAGS =

LDFLAGS = -L $(LIBPATH) -lft

SRC =	main.c\
		ft_choose.c\
		alloc.c\
		dlist_new_master.c\
		dlist_new_mmap.c\
		ft_add_data_mmap_pages.c\
		ft_add_data_mmap_adresses.c\
		ft_show_alloc.c\
		ft_real_free.c\
		libft/ft_itoa_base.c\
		libft/ft_putstr.c\
		libft/ft_putnbr.c\
		libft/nik_the_norm.c\
		libft/ft_putchar.c\
		libft/ft_strncpy.c\

OBJ = $(SRC:.c=.o)

all: $(LIB) $(NAME)

$(NAME):	$(OBJ)
	@$(CC) $(LDFLAGS) -o $@ $^
	@$(SO) $(OBJ)
	@ln -s libft_malloc_$(HOSTTYPE).so libft_malloc.so

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
