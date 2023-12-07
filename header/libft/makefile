NAME		= libft.a
LIBRARY		= ar -rcs
CC			= gcc
RM			= rm -rf

HEADER  	= includes/libft.h includes/get_next_line.h

INCLUDES	= -Iincludes
CFLAGS		= -Wall -Werror -Wextra $(INCLUDES)

#	Objects move to build folder

BUILD		= objs
MOVE		= mv $(OBJS) $(BUILD)
B_OBJS_PATH	= $(addprefix $(BUILD)/, $(B_OBJS))

#	SRCS

MANDATORY	= ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
	ft_strlen.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c \
	ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c \
	ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_atoli.c
B_SRC		+= $(MANDATORY)
MAND_PATH	= $(addprefix mandatory/, $(MANDATORY))
SRC			+= $(MAND_PATH)

LST			= ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c
B_SRC		+= $(LST)
LST_PATH	= $(addprefix lst/, $(LST))
SRC			+= $(LST_PATH)

MATRIX		= ft_mtx_cpy.c ft_mtx_cut.c ft_mtx_free.c
B_SRC		+= $(MATRIX)
MTX_PATH	= $(addprefix matrix/, $(MATRIX))
SRC			+= $(MTX_PATH)

GNL			= get_next_line.c get_next_line_utils.c
B_SRC		+= $(GNL)
GNL_PATH	= $(addprefix get_next_line/, $(GNL))
SRC			+= $(GNL_PATH)

# COLOUR DEFINITION #

YELLOW	:= \033[33m
RED     := \033[0;31m
BLUE    := \033[0;34m
GREEN   := \033[1;32m
WHITE   := \033[0;37m
RESET   := \033[0m
UP		= "\033[A"
CUT		= "\033[K"

#	OBJS

OBJS		= ${SRC:.c=.o}
B_OBJS		= $(B_SRC:.c=.o)

all:		${NAME}

.c.o:		%.o : %.c
		${CC} ${CFLAGS} -c $< -o $(<:.c=.o)
		@printf $(UP)$(CUT)

${NAME}:	${OBJS}
		@$(MOVE)
		@${LIBRARY} ${NAME} ${B_OBJS_PATH}
		@ranlib ${NAME}
		@echo "$(GREEN)<---> Libft Compiled! <--->$(RESET)"

clean:
		@${RM} ${B_OBJS_PATH}

fclean:		clean
		@${RM} ${NAME}
		@echo "$(YELLOW)<---> Libft Removed! <--->$(RESET)"

re:			fclean all

.PHONY: clean all fclean re