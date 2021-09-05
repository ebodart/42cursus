# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/20 18:40:29 by ebodart           #+#    #+#              #
#    Updated: 2021/09/05 20:01:47 by ebodart          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc -g

CFLAGS		= -Wall -Wextra -Werror

SRCDIR		= ./srcs/

SRCNAME		= push_swap.c \
				deal_with_args.c \
				split.c \
				utils.c \
				check_stack.c \
				exit.c \
				swap.c \
				push.c \
				rotate.c \
				re_rotate.c \
				fill_stack.c \
				small_algorithm.c \
				position.c \
				position_chunk.c \
				big_algorithm.c \
				nbr_suite.c \
				chunk_algorithm.c \

SRCNAMECHK		= checker.c \
				deal_with_args.c \
				split.c \
				check_stack.c \
				get_next_line.c \
				get_next_line_utils.c \
				exit.c \
				swap.c \
				push.c \
				rotate.c \
				re_rotate.c \
				fill_stack.c \
				utils.c \
				nbr_suite.c \
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