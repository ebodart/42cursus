# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/18 21:13:42 by ebodart           #+#    #+#              #
#    Updated: 2021/05/21 12:06:48 by ebodart          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= gcc

CFLAGS		= -Wall -Wextra -Werror

LIBDIR		= ./libft/

SRCDIR		= ./srcs/

INCLDIR		= ./includes

SRCNAME		= ft_printf.c \
				ft_fill_print.c \
				ft_conv_char.c \
				ft_conv_string.c \
				ft_conv_percent.c \
				ft_conv_integer.c \
				ft_write_flags.c \
				
SRCS		= ${addprefix ${SRCDIR}, ${SRCNAME}}

LIBFTOBJS   = ${LIBDIR}*.o


OBJS		= ${SRCS:.c=.o}

.c.o:		
			$(CC) ${CFLAGS} -I ./includes/  -c $< -o ${<:.c=.o}

LIBNAME		= libft.a

NAME		= libftprintf.a

${NAME}:	${OBJS}
			make -C $(LIBDIR)
			ar rc $(NAME) ${LIBFTOBJS} $(OBJS)
			ranlib $(NAME)

all:		${NAME}

clean:
			make -C $(LIBDIR) clean
			rm -f $(OBJS)

fclean:		clean
			make -C $(LIBDIR) fclean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re