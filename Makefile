# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slambert <slambert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/11 13:28:23 by slambert          #+#    #+#              #
#    Updated: 2025/11/20 13:41:35 by slambert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = 	push_swap.c swap.c push.c rotate.c reverse_rotate.c indexing_stuff.c \
		input_handler.c utils.c ft_atoi_checked.c chunk_sort.c operations.c

OBJS = ${SRC:.c=.o}

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I .

.o:.c
		${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		${CC} ${CFLAGS} ${OBJS} -o ${NAME}


all:	${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re