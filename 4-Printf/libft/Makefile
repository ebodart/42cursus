# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/18 21:13:42 by ebodart           #+#    #+#              #
#    Updated: 2020/12/04 13:06:28 by ebodart          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc

NAME		= libft.a

FLAGS		= -Wall -Wextra -Werror

SRCS		= ft_strlen.c \
				ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strncmp.c \
				ft_memset.c \
				ft_bzero.c \
				ft_memcpy.c \
				ft_memccpy.c \
				ft_memmove.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strlcpy.c \
				ft_strlcat.c \
				ft_strnstr.c \
				ft_atoi.c \
				ft_calloc.c \
				ft_strdup.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_split.c \
				ft_itoa.c \
				ft_strmapi.c \
				ft_putchar_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_putstr_fd.c

BONUS		= ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c

OBJS		= $(SRCS:.c=.o)

OBJSBONUS	= $(BONUS:.c=.o)


all:		$(NAME)


$(NAME):	$(OBJS)
			ar rc $(NAME) $(OBJS)
			ranlib $(NAME)


bonus: $(OBJS) $(OBJSBONUS)
		ar rc $(NAME) $(OBJS) $(OBJSBONUS)
		ranlib $(NAME)


.c.o:		
			$(CC) $(FLAGS) -c $< -o $(<:.c=.o)


clean:
			rm -f $(OBJS) $(OBJSBONUS)


fclean:		clean
			rm -f $(NAME) $(SO)


re:			fclean all


.PHONY:		all bonus clean fclean re
