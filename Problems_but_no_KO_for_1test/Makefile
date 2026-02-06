# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irdzhupy <irdzhupy@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/23 10:02:13 by irdzhupy          #+#    #+#              #
#    Updated: 2026/01/23 10:21:04 by irdzhupy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line

SRCS = get_next_line.c get_next_line_utils.c main.c

OBJS = ${SRCS:.c=.o}
CC = cc
FLAGS = -Wall -Wextra -Werror
REMOVE = rm -f

all: ${NAME}

${NAME}: ${OBJS}
	$(CC) ${FLAGS} -o ${NAME} ${OBJS}

.c.o:
	${CC} ${FLAGS} -c $< -o $@
clean:
	rm -f ${OBJS}
fclean: clean
	rm -f ${NAME}
re:	fclean all

.PHONY: all clean fclean re
