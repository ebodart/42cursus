# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/08 16:58:23 by ebodart           #+#    #+#              #
#    Updated: 2021/10/04 14:36:13 by ebodart          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the program

NAME		= fractol


# Compilation

CC			= gcc


# Flags used during compilation

CFLAGS		= -Wall -Wextra -Werror


# Folders

SRCS_DIR	= ./srcs/

OBJ_DIR		= ./obj/

INC_DIR		= ./includes/

LIB_DIR		= ./libft/

MLX_DIR 	= ./minilibx/

MLX_LIB 	= -L./mlx -lmlx -lXext -lX11 -lbsd -L./libft -lft -lm

#MLX_FLAGS 	= -lmlx -framework OpenGL -framework AppKit


# Source files to compile

SRCS_FILES	= main.c \


# .c files become .o object files

OBJ_FILES 	= $(SRCS_FILES:.c=.o)


# Folder Paths
				
SRCS		= $(addprefix $(SRCS_DIR), $(SRCS_FILES))

OBJ			= $(addprefix $(OBJ_DIR), $(OBJ_FILES))

LIB 		= $(addprefix $(LIB_DIR), libft.a)

MLX 		= ./mlx/libmlx.a

INCLUDES	= -I includes



all:		$(NAME)

%.o: 		%.c
			$(CC) $(CFLAGS) -Imlx -c $< -o $@ 
			

$(NAME):	$(OBJ) $(LIB) 
			$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^

$(MLX):

bonus: $(CHK)

clean:
			rm -f $(OBJS) $(OBJSCHK)

fclean:		clean
			rm -f $(NAME) $(CHK)

re:			fclean all

.PHONY:		all clean fclean re bonus