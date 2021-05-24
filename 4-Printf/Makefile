# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/18 21:13:42 by ebodart           #+#    #+#              #
#    Updated: 2021/05/24 18:02:19 by ebodart          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= gcc

CFLAGS		= -Wall -Wextra -Werror

SRCDIR		= ./srcs/

INCLDIR		= ./includes

SRCNAME		= ft_printf.c \
				ft_fill_print.c \
				ft_conv_char.c \
				ft_conv_string.c \
				ft_conv_percent.c \
				ft_conv_integer.c \
				ft_conv_uninteger.c \
				ft_int_in_str.c \
				ft_write_flags.c \
				
SRCS		= ${addprefix ${SRCDIR}, ${SRCNAME}}

OBJS		= ${SRCS:.c=.o}

.c.o:		
			$(CC) ${CFLAGS} -I ./includes/  -c $< -o ${<:.c=.o}

NAME		= libftprintf.a

${NAME}:	${OBJS}
			ar rc $(NAME) $(OBJS)
			ranlib $(NAME)

all:		${NAME}

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re