# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leon <leon@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 03:18:02 by leon              #+#    #+#              #
#    Updated: 2022/11/18 04:53:19 by leon             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

FILES = ft_printf

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./
OBJS = $(SRCS:.c=.o)

LIBFT_DIR = ./libft/
LIBFT_NAME = ft

$(NAME): $(OBJS)
	$(AR) $@ $<

$(OBJS): makelibft

%.o: %.c
	$(CC) $(CFLAGS) -L${LIBFT_DIR} -l${LIBFT_NAME} -c $< -o $@

makelibft:
	cd ${LIBFT_DIR} && make

fcleanlibft:
	cd ${LIBFT_DIR} && make fclean

all: $(NAME)

clean: fcleanlibft
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: clean all

.PHONY: all clean fclean re