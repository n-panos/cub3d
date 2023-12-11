NAME	= libmlx.a
LIBRARY	= ar -rcs
CC		= cc
RM		= rm -rf

SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
SRC+= mlx_png.c mlx_mouse.m

OBJ1	= $(SRC:.c=.o)
OBJ		= $(OBJ1:.m=.o)

CFLAGS	+= -O2 -w

# COLOUR DEFINITION #

YELLOW	:= \033[33m
RED     := \033[0;31m
BLUE    := \033[0;34m
GREEN   := \033[1;32m
WHITE   := \033[0;37m
RESET   := \033[0m
UP		= "\033[A"
CUT		= "\033[K"

# add to match string put with X11 in size and position
CFLAGS	+= -DSTRINGPUTX11

# changed the following 8 lines to silence all the warnings created
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@
	@printf $(UP)$(CUT)
%.o : %.m
	$(CC) $(CFLAGS) -c $< -o $@ 
	@printf $(UP)$(CUT)

all: $(NAME)

$(NAME):	$(OBJ)
	@$(LIBRARY) $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(GREEN)<---> Mlx Compiled! <--->$(RESET)"

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME) *~
	@$(RM) mlx_app
	@echo "$(YELLOW)<---> Mlx Removed! <--->$(RESET)"

re: fclean all
