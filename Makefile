# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apodader <apodader@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 10:05:31 by lsoto-do          #+#    #+#              #
#    Updated: 2024/09/07 19:55:59 by apodader         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = cub3D
NAME_BONUS  = $(NAME)_bonus
CFLAGS      = -O3 -g -Wall -Wextra -Werror -MMD #-fsanitize=address
RM          = rm -rf
CC          = cc

# Paths
SRCS_PATH       = src
BONUS_PATH      = bonus/
OBJS_PATH       = obj
LIB_PATH        = ./libft
MLX_LINUX_PATH  = ./minilibx-linux/
MLX_MAC_PATH    = ./minilibx_opengl_20191021/
INCS            = -I./includes/ -I$(LIB_PATH)/includes -I$(MLX_PATH)

# Libft & Minilibx Configurations
LIB             = $(LIB_PATH)/libft.a
L_MLX           = $(MLX_PATH)libmlx.a
FRAME_LINUX     = -lXext -lX11 -lm -lz
FRAME_MAC       = -framework OpenGL -framework AppKit

# System-Specific Configurations
OS              = $(shell uname -s)
ifeq ($(OS), Linux)
    MLX_PATH = $(MLX_LINUX_PATH)
    FRAME = $(FRAME_LINUX)
    KEYS = -D LINUX_KEYS=1
else
    MLX_PATH = $(MLX_MAC_PATH)
    FRAME = $(FRAME_MAC)
    KEYS = -D LINUX_KEYS=0
endif

# Colors
DEL_LINE =       \033[2K
ITALIC =        \033[3m
BOLD =          \033[1m
DEF_COLOR =     \033[0;39m
GRAY =          \033[0;90m
RED =           \033[0;91m
GREEN =         \033[0;92m
YELLOW =        \033[0;93m
BLUE =          \033[0;94m
MAGENTA =       \033[0;95m
CYAN =          \033[0;96m
WHITE =         \033[0;97m
BLACK =         \033[0;99m
ORANGE =        \033[38;5;209m
BROWN =         \033[38;2;184;143;29m
DARK_GRAY =     \033[38;5;234m
MID_GRAY =      \033[38;5;245m
DARK_GREEN =    \033[38;2;75;179;82m
DARK_YELLOW =   \033[38;5;143m

LDFLAGS = -L$(LIB_PATH) -lft -L$(MLX_PATH) -lmlx $(FRAME) -lm

# Source Files
SRC_FILES       = $(wildcard $(SRCS_PATH)/**/*.c) $(wildcard $(SRCS_PATH)/*.c)
BONUS_FILES     = $(wildcard $(BONUS_PATH)/**/*.c) $(wildcard $(BONUS_PATH)/*.c)

OBJS            = $(patsubst $(SRCS_PATH)%.c, $(OBJS_PATH)%.o, $(SRC_FILES))
OBJS_BONUS      = $(patsubst $(BONUS_PATH)%.c, $(OBJS_PATH)%.o, $(BONUS_FILES))

# Dependency Files
DEPS            = $(OBJS:.o=.d)
DEPS_BONUS      = $(OBJS_BONUS:.o=.d)

# Rules
all: $(LIB) $(L_MLX) $(NAME)

$(LIB): $(LIB_PATH)/Makefile
	@echo "$(BLUE)◎ $(BROWN)Building libft$(DEF_COLOR)"
	@$(MAKE) -C $(LIB_PATH) > /dev/null 2>&1

$(L_MLX): $(MLX_PATH)/Makefile
	@echo "$(BLUE)◎ $(BROWN)Building MinilibX$(DEF_COLOR)"
	@$(MAKE) -C $(MLX_PATH) > /dev/null 2>&1

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c Makefile
	@mkdir -p $(dir $@)
	@echo "$(BLUE)Compiling   $(MAGENTA)→   $(CYAN)$< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(INCS) $(KEYS) -c $< -o $@

$(NAME): $(OBJS) $(LIB) $(L_MLX)
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)
	@echo "$(GREEN)\nCreated $(NAME) executable ✓$(DEF_COLOR)\n"

bonus: $(NAME_BONUS)

$(OBJS_PATH)/%.o: $(BONUS_PATH)/%.c
	@mkdir -p $(dir $@)
	@echo "$(BLUE)Compiling   $(MAGENTA)→   $(CYAN)$< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(INCS) $(KEYS) -c $< -o $@

$(NAME_BONUS): $(OBJS_BONUS) $(LIB) $(L_MLX)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LDFLAGS) -o $(NAME_BONUS)
	@echo "$(GREEN)\nCreated $(NAME_BONUS) executable ✓$(DEF_COLOR)\n"

clean:
	@$(RM) $(OBJS_PATH)
	@echo "$(ORANGE)Objects cleaned!$(DEF_COLOR)"
	@$(MAKE) -C $(LIB_PATH) clean > /dev/null 2>&1
	@$(MAKE) -C $(MLX_PATH) clean > /dev/null 2>&1

fclean: clean
	@$(RM) $(NAME) $(NAME_BONUS)
	@$(MAKE) -C $(LIB_PATH) fclean > /dev/null 2>&1
	@echo "$(ORANGE)Executables cleaned!$(DEF_COLOR)"

re: fclean all

-include $(DEPS) $(DEPS_BONUS)

.PHONY: all fclean clean re bonus
