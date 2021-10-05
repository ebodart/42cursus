# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/08 16:58:23 by ebodart           #+#    #+#              #
#    Updated: 2021/10/05 14:31:33 by ebodart          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the program

NAME		= fractol


# Compilation

CC			= gcc


# Flags used during compilation

CFLAGS		= -Wall -Wextra -Werror

MLX_FLAGS 	= -Imlx -lmlx -framework OpenGL -framework AppKit


# Folders

SRCS_DIR	= ./srcs/

LIB_DIR		= ./libft/

MLX_DIR 	= ./minilibx/


# Source files to compile

SRCS_FILES	= main.c \


# .c files become .o object files

OBJS 	= $(SRCS:.c=.o)


# Folder Paths
				
SRCS		= $(addprefix $(SRCS_DIR), $(SRCS_FILES))

INCLUDES	= -I includes

LIB			= $(addprefix $(LIB_DIR), libft.a)


all:		$(NAME)

$(NAME):	$(OBJS)
			make -C $(LIB_DIR)
			make -C $(MLX_DIR)
			$(CC) $(CFLAGS) $(INCLUDES) $(LIB) $(OBJS) $(MLX_FLAGS) -o $(NAME)

clean:
			rm -f $(OBJS)
			cd libft && make clean
			cd minilibx && make clean

fclean:		clean
			rm -f $(NAME)
			cd libft && make fclean

re:			fclean all

.PHONY:		all clean fclean re bonus