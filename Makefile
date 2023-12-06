NAME		= cub3D
CC			= gcc
RM			= rm -rf

DEBUG		= -ggdb -g3
SANITIZE	= -fsanitize=address

#	Objects move to build folder

BUILD		= objs
MKDIR		= mkdir $(BUILD)
MOVE		= mv $(OBJS) $(BUILD)
B_OBJS_PATH	= $(addprefix $(BUILD)/, $(B_OBJS))

#	LIBRARIES

LIBRARIES	= 
LIBFT		= -L header/libft
#MLX			= -Lheader/mlx -lmlx -framework OpenGL -framework AppKit

INCLUDES	= $(HEADER) #$(I_LIBFT)
HEADER		= -Iheader
#I_LIBFT		= -Iheader/libft

#	FLAGS

CFLAGS		= -Wall -Werror -Wextra $(INCLUDES)
LDFLAGS		= $(LIBRARIES)

#	MAIN

SRC			+= main.c
B_SRC		+= main.c

##	PARSER

PARSER		= parser.c
B_SRC		+= $(PARSER)
PARSER_PATH	= $(addprefix parser/src/, $(PARSER))
SRC			+= $(PARSER_PATH)

# COLOUR DEFINITION #

RED     := \033[0;31m
BLUE    := \033[0;34m
GREEN   := \033[1;32m
WHITE   := \033[0;37m
RESET   := \033[0m

OBJS		= $(SRC:.c=.o)
B_OBJS		= $(B_SRC:.c=.o)

all:	$(NAME)

.c.o:	%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
	$(MKDIR)
	$(MOVE)
	$(CC) $(LDFLAGS) $(B_OBJS_PATH) $(LIBFT) -o $@
	@echo "$(GREEN)<---> Cub3D Compiled! ⌐(ಠ۾ಠ)¬ <--->$(RESET)"

$(LIBFT):
	@make -C header/libft

debug:	CFLAGS	+= $(DEBUG) $(SANITIZE)
debug:	re

clean:
	$(RM) $(BUILD)

fclean:	clean
	$(RM) $(NAME)
	@make fclean -C header/libft
	@echo "$(GREEN)<==========> ALL REMOVED <==========>$(RESET)"

re:	fclean all

.PHONY: clean all fclean re