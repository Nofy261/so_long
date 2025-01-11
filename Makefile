# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/20 14:08:07 by nolecler          #+#    #+#              #
#    Updated: 2025/01/11 11:48:11 by nolecler         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

FSRCS = main.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \
		utils.c \
		open_map.c \
		parsing.c \
		check_pec.c \
		parse_map.c \

OFILES = $(FSRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra -I./MLX42/include

MLXFLAGS = -ldl -lX11 -lglfw -lm -lz -lbsd -lXext ./MLX42/build/libmlx42.a -pthread

all: mlx $(NAME)
	@echo "\033[32mCompilation successful!\033[0m"

mlx:
	@if [ -d "./MLX42" ]; then \
		echo "\033[32;1mMLX42 already exists.\033[0m"; \
	else \
		echo "\033[33;1mCloning and building MLX42...\033[0m"; \
		git clone https://github.com/codam-coding-college/MLX42.git > /dev/null 2>&1; \
		cmake ./MLX42 -B ./MLX42/build > /dev/null 2>&1; \
		cmake --build ./MLX42/build -j4 > /dev/null 2>&1; \
		echo "\033[32;1mMLX42 built successfully.\033[0m"; \
	fi

$(NAME): $(OFILES)
	@$(CC) $(CFLAGS) $(OFILES) $(MLXFLAGS) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@rm -f $(OFILES)
	@echo "\033[34mObject files cleaned.\033[0m"

cleanmlx:
	@rm -rf MLX42
	@echo "\033[34mMLX42 cleaned.\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[34mBinary and object files cleaned.\033[0m"

re: fclean all

.PHONY: all clean fclean re mlx