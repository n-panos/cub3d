NAME		= cub3D
CC			= gcc
RM			= rm -rf

DEBUG		= -ggdb -g3
SANITIZE	= -fsanitize=address

#	Objects move to build folder

BUILD		= objs
MOVE		= mv $(OBJS) $(BUILD)
B_OBJS_PATH	= $(addprefix $(BUILD)/, $(B_OBJS))

#	LIBRARIES

INCLUDES	= $(HEADER) $(MLX_H)
HEADER		= -Iheader
MLX_H		= -Iheader/mlx

LIBRARIES	= $(LIBFT) $(MLX)
MLX			= -Lheader/mlx -lmlx -framework OpenGL -framework AppKit
LIBFT		= header/libft/libft.a

#	FLAGS

CFLAGS		= -Wall -Werror -Wextra $(INCLUDES)
LDFLAGS		= $(LIBRARIES)

########		INCLUDE PARTS		########

#	MAIN

SRC			+= main.c
B_SRC		+= main.c

##	PARSER

PARSER		= distribute.c init_utils.c init.c map_paint.c open_file.c parser.c valid_map.c
B_SRC		+= $(PARSER)
PARSER_PATH	= $(addprefix parser/src/, $(PARSER))
SRC			+= $(PARSER_PATH)

##	GAME

GAME		= draw_utils.c game_init.c game.c image.c
B_SRC		+= $(GAME)
GAME_PATH	= $(addprefix game/src/, $(GAME))
SRC			+= $(GAME_PATH)

# COLOUR DEFINITION #

YELLOW	:= \033[33m
RED     := \033[0;31m
BLUE    := \033[0;34m
GREEN   := \033[1;32m
WHITE   := \033[0;37m
RESET   := \033[0m
UP		= "\033[A"
CUT		= "\033[K"

OBJS		= $(SRC:.c=.o)
B_OBJS		= $(B_SRC:.c=.o)

all:	$(NAME)

.c.o:	%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
	@printf $(UP)$(CUT)

$(NAME):	$(OBJS)
	@make -C header/libft
	@make -C header/mlx
	@$(MOVE)
	@$(CC) $(LDFLAGS) $(B_OBJS_PATH) -o $@
	@echo "$(GREEN)<==========> Cub3D Compiled! ⌐(ಠ۾ಠ)¬ <==========>$(RESET)"

debug:	CFLAGS	+= $(DEBUG) $(SANITIZE)
debug:	LDFLAGS	+= $(SANITIZE)
debug:	re

clean:
	@$(RM) $(B_OBJS_PATH)

fclean:	clean
	@$(RM) $(NAME)
	@make fclean -C header/libft
	@make fclean -C header/mlx
	@echo "$(YELLOW)<==========> ALL REMOVED <==========>$(RESET)"

re:	fclean all

.PHONY: clean all fclean re