# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 03:18:02 by leon              #+#    #+#              #
#    Updated: 2022/11/19 07:42:18 by lperroti         ###   ########.fr        #
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

LIBFT_DIR = libft/
LIBFT_NAME = libft.a

$(NAME): $(OBJS)
	cp ${LIBFT_DIR}${LIBFT_NAME} $@
	${AR} $@ $<

$(OBJS): makelibft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

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

bonus:
	cp ${LIBFT_DIR}${LIBFT_NAME} $@
	${AR} $@ $<

.PHONY: all clean fclean re