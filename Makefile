# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hichikaw <hichikaw@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/09 23:37:35 by ichikawahik       #+#    #+#              #
#    Updated: 2025/07/19 14:00:54 by hichikaw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iminilibx-linux -Ilibft
SRC = src/fractol.c src/mandelbrot.c src/julia.c src/calculate.c \
      src/init.c src/validate.c src/ft_atof.c src/render.c \
      src/keyboard_operation.c src/mouse_operation.c src/print_msg.c
OBJS = $(SRC:.c=.o)
LIBFT = libft/libft.a
MLX = minilibx-linux/libmlx.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) -lXext -lX11 -lm -o $(NAME)

$(LIBFT): FORCE
	make -C libft

FORCE:

$(MLX):
	make -C minilibx-linux

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C libft clean
	make -C minilibx-linux clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re FORCE
