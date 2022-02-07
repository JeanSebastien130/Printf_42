# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmorel <jmorel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/13 10:33:00 by jmorel            #+#    #+#              #
#    Updated: 2022/01/20 11:19:28 by jmorel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = ./Libft/libft.a
CC = gcc
FLAGS = -c -Wall -Wextra -Werror
INCLUDES = -I./Include
NAME = libftprintf.a

SRCS =      Sources/ft_printf.c	\
			Sources/ft_tools.c	\
			Sources/ft_hexa.c	\
			Sources/ft_unsigned.c \
			Sources/ft_pointer.c			

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) -C ./Libft
	cp -r Libft/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	$(MAKE) clean -C ./libft
 
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re : fclean all