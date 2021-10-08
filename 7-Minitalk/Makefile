# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/04 15:40:58 by ebodart           #+#    #+#              #
#    Updated: 2021/10/05 10:18:06 by ebodart          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc -g

CFLAGS		= -Wall -Wextra -Werror

INCLUDES	= -I include


SERVER_DIR 	= ./src_server/

CLIENT_DIR	= ./src_client/

LIBFT_DIR	= ./libft/


SERVER_FILE = ft_server.c

CLIENT_FILE  = ft_client.c


LIBFT		=  cd libft && make

LIBFT_PATH	= libft/libft.a

SERVER_PATH  = $(addprefix $(SERVER_DIR), $(SERVER_FILE))

CLIENT_PATH  = $(addprefix $(CLIENT_DIR), $(CLIENT_FILE))


SERVER_OBJS = $(SERVER_PATH:.c=.o)

CLIENT_OBJS = $(CLIENT_PATH:.c=.o)


SERVER_NAME	= server

CLIENT_NAME = client

				
all:		$(NAME)

$(NAME):	libft_comp server client
			
libft_comp:	
			$(LIBFT)

server:		$(SERVER_OBJS)
			$(CC) $(CFLAGS) $(SERVER_OBJS) $(LIBFT_PATH) -o $(SERVER_NAME)

client:		$(CLIENT_OBJS)
			$(CC) $(CFLAGS) $(CLIENT_OBJS) $(LIBFT_PATH) -o $(CLIENT_NAME)

.c.o:
			$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

clean:
			rm -f $(SERVER_OBJS) $(CLIENT_OBJS)
			cd libft && make clean
			

fclean:		clean
			rm -f $(SERVER_NAME) $(CLIENT_NAME)
			cd libft && make fclean

re:			fclean all

.PHONY:		all clean fclean re bonus