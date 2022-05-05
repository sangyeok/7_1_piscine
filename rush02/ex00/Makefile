# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeyukim <hyeyukim@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/01 21:10:36 by hyeyukim          #+#    #+#              #
#    Updated: 2022/05/01 21:11:33 by hyeyukim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC			= main.c check_nums.c check_exists.c ft_get_ready.c ft_nodes.c ft_read.c ft_puts.c ft_parse.c ft_sets.c ft_sort.c
OBJS		= ${SRC:.c=.o}
HEAD		= ft_header.h
NAME		= rush-02
GCC			= gcc
CFLAGS		= -Wall -Wextra -Werror

all:		${NAME}

.c.o:
			${GCC} ${CFLAGS} -c -I ${HEAD} $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${GCC} ${CFLAGS} -o ${NAME} ${OBJS}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
