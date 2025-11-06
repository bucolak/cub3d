# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bucolak <bucolak@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/24 02:30:48 by iarslan           #+#    #+#              #
#    Updated: 2025/11/06 18:07:17 by bucolak          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR     := src
EXIT_DIR    := exit
PARSING_DIR := parsing
INC_DIR     := include
LIBFT_DIR   := libft
GNL_DIR     := get_next_line
MLX_DIR     := minilibx-linux

NAME        := cub3d

CC          := cc
CFLAGS      := -g -Wall -Wextra -Werror #look for -g flag
INCS        := -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR) -I$(GNL_DIR)

MLX_LDFLAGS := -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
LIBFT_LDFLAGS := -L$(LIBFT_DIR) -lft

# EXIT klasörü (src/exit içinde)
EXIT_SRC := $(SRC_DIR)/exit/exit_1.c

# SRC klasörü (main.c eklenecek)
SRC_MAIN := $(SRC_DIR)/main.c \
			 $(SRC_DIR)/init.c

# PARSING klasörü
PARSING_SRC := 	$(SRC_DIR)/parsing/map_parsing/element_parse.c \
			   	$(SRC_DIR)/parsing/map_parsing/element_identifier.c \
				$(SRC_DIR)/parsing/map_parsing/rgb_parse.c \
				$(SRC_DIR)/parsing/controls/is_map_close.c \
              	$(SRC_DIR)/parsing/controls/is_valid_mapp.c \
				$(SRC_DIR)/parsing/controls/main_control.c \
               	$(SRC_DIR)/parsing/main_parser.c \
               	$(SRC_DIR)/parsing/parsing_utils.c

GNL_SRC := $(GNL_DIR)/get_next_line.c \
           $(GNL_DIR)/get_next_line_utils.c

# Tüm kaynak dosyaları
SRC := $(EXIT_SRC) $(PARSING_SRC) $(SRC_MAIN) $(GNL_SRC)

OBJ := $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(INCS) $(LIBFT_DIR)/libft.a $(MLX_LDFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean || true
	$(RM) $(OBJ)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean || true
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re