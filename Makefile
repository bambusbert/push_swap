# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slambert <slambert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/11 13:28:23 by slambert          #+#    #+#              #
#    Updated: 2025/11/19 16:52:01 by slambert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#TODO call makefile from libft from here
#TODO without relinking
NAME = push_swap

SRC = push_swap.c swap.c push.c rotate.c reverse_rotate.c indexing_stuff.c input_handler.c

OBJS = ${SRC:.c=.o}

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I .

LIBFT = libft/libft.a

.o:.c
		${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

$(NAME): ${LIBFT} ${OBJS}
		${CC} ${CFLAGS} ${OBJS} ${LIBFT} -o ${NAME}

${LIBFT}:
		@make -C libft bonus
#aslfjnehjfvbwejkbv

all:	${NAME}

clean:
		${RM} ${OBJS}
		@make -C libft clean

fclean: clean
		${RM} ${NAME}
		@make -C libft fclean

re: fclean all

.PHONY: all clean fclean re