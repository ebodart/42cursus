# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/20 18:40:29 by ebodart           #+#    #+#              #
#    Updated: 2021/07/23 13:57:42 by ebodart          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

SRCDIR		= ./srcs/

SRCNAME		= push_swap.c \
				utils.c \
				exit.c \
				swap.c \
				push.c \
				rotate.c \
				re_rotate.c \
				printf.c \
				fill_stack.c \
				small_algorithm.c \
				
				
SRCS		= ${addprefix ${SRCDIR}, ${SRCNAME}}

OBJS		= ${SRCS:.c=.o}

INCLUDES	= -I includes

NAME		= push_swap

all:		${NAME}

%.o: 		%.c
			$(CC) -o $@ -c $<
			

${NAME}:	${OBJS}
			$(CC) ${CFLAGS} ${INCLUDES} -o $@ $^

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re