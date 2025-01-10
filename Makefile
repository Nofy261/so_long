# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/20 14:08:07 by nolecler          #+#    #+#              #
#    Updated: 2025/01/10 14:59:03 by nolecler         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

FSRCS = main.c \
		get_next_line.c \
		get_next_line_utils.c \
		utils.c \
		open_map.c \

OFILES = $(FSRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra -I./MLX42/include

MLXFLAGS = -ldl -lX11 -lglfw -lm -lz -lbsd -lXext ./MLX42/build/libmlx42.a -pthread

all: mlx $(NAME)

# mlx :
#     @if ls | grep -q "MLX42"; then \
#         clear; \
#         echo "\033[32;47;1m** MLX42 already exist **\033[1;m"; \
#     else \
#         git clone https://github.com/codam-coding-college/MLX42.git; \
#         cmake ./MLX42 -B ./MLX42/build; \
#         make -C ./MLX42/build --no-print-directory -j4; \
#         make --directory ./MLX42/build; \
#     fi

mlx:
	@if [ -d "./MLX42" ]; then \
		echo "\033[32;47;1m** MLX42 already exists **\033[1;m"; \
	else \
		git clone https://github.com/codam-coding-college/MLX42.git; \
		cmake ./MLX42 -B ./MLX42/build; \
		cmake --build ./MLX42/build -j4; \
	fi

$(NAME): $(OFILES)
	$(CC) $(CFLAGS) $(OFILES) $(MLXFLAGS) -o $(NAME)

clean:
	rm -f $(OFILES)

cleanmlx:
	rm -rf MLX42

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

# .PHONY: all clean fclean re
.PHONY: all clean fclean re mlx
