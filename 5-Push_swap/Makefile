# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/20 18:40:29 by ebodart           #+#    #+#              #
#    Updated: 2021/08/07 12:19:30 by ebodart          ###   ########.fr        #
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
				position.c \
				big_algorithm.c \

SRCNAMECHK		= checker.c \
				get_next_line.c \
				get_next_line_utils.c \
				exit.c \
				swap.c \
				push.c \
				rotate.c \
				re_rotate.c \
				fill_stack.c \
				utils.c \
				position.c \

				
				
				
SRCS		= ${addprefix ${SRCDIR}, ${SRCNAME}}

SRCSCHK		= ${addprefix ${SRCDIR}, ${SRCNAMECHK}}

OBJS		= ${SRCS:.c=.o}

OBJSCHK		= ${SRCSCHK:.c=.o}

INCLUDES	= -I includes

NAME		= push_swap

CHK			= checker

all:		${NAME}

%.o: 		%.c
			$(CC) -o $@ -c $<
			

${NAME}:	${OBJS}
			$(CC) ${CFLAGS} ${INCLUDES} -o $@ $^

$(CHK): $(OBJSCHK)
		$(CC) ${CFLAGS} ${INCLUDES} -o $@ $^

bonus: $(CHK)

clean:
			rm -f $(OBJS) $(OBJSCHK)

fclean:		clean
			rm -f $(NAME) $(CHK)

re:			fclean all

.PHONY:		all clean fclean re bonus