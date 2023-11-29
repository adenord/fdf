# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adenord <adenord@student.42mulhouse.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/17 15:08:32 by adenord           #+#    #+#              #
#    Updated: 2023/11/29 10:39:33 by adenord          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --silent

MLX42_LIB := MLX42/build/libmlx42.a
MLX42_BUILD_PATH := ./MLX42
SRCS := srcs/arg_validator.c srcs/breisen.c srcs/breisen_utils.c \
srcs/calculator_pos.c srcs/center.c srcs/clear.c srcs/hooks.c \
srcs/liner.c srcs/mlx_stuff.c srcs/parser.c srcs/parser_utils.c \
srcs/put_pixel.c srcs/rotation.c srcs/rotation_handler.c srcs/rotation_utils.c \
srcs/zoom.c srcs/freeman.c

OBJS := $(SRCS:.c=.o)
CC := gcc
CFLAGS := -Wall -Wextra -Werror
CPPFLAGS := -I includes -I MLX42/include/MLX42 -I srcs/libft/
NAME := fdf
MAIN := fdf.c
LIBFT_LIB := srcs/libft/libft.a
MLX_LIB := MLX42/build/libmlx42.a

all : $(NAME)

writing : 
	echo "\033[32mCreating your binary ...\033[0m"

$(MLX42_LIB) :
	cmake $(MLX42_BUILD_PATH) -B $(MLX42_BUILD_PATH)/build
	cmake --build $(MLX42_BUILD_PATH)/build -j4

$(LIBFT_LIB) :
	make -C srcs/libft

$(NAME) : writing $(MLX42_LIB) $(OBJS) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(MLX_LIB) $(MAIN) $(OBJS) $(LIBFT_LIB) -o $(NAME) -lglfw
	echo "\033[32mDone !\033[0m"


clean :
	echo "\033[32mObjects files have been deleted.\033[0m"
	$(RM) $(OBJS)
	make clean -C srcs/libft
	make clean -C MLX42/build

fclean : clean
	echo "\033[32mBinary and depedencies have been deleted.\033[0m"
	$(RM) -r $(LIBFT_LIB) fdf MLX42/build

re : fclean all

