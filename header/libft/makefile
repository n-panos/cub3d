MANDATORY	= ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
	ft_strlen.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c \
	ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c \
	ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_atoli.c
MAND_PATH	= $(addprefix mandatory/, $(MANDATORY))
SRC			+= $(MAND_PATH)

LST			= ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c
LST_PATH	= $(addprefix lst/, $(LST))
SRC			+= $(LST_PATH)

MATRIX		= ft_mtx_cpy.c ft_mtx_cut.c ft_mtx_free.c
MTX_PATH	= $(addprefix matrix/, $(MATRIX))
SRC			+= $(MTX_PATH)

OBJS		= ${SRC:.c=.o}

LIBRARY		= ar -rcs
NAME		= libft.a
HEADER  	= libft.h
CC			= gcc
RM			= rm -rf

CFLAGS	= -Wall -Werror -Wextra -g

.c.o:		%.o : %.c
					@${CC} ${CFLAGS} -c $< -o $(<:.c=.o)

all:		${NAME}

${NAME}:	${OBJS} $(HEADER)
				@${LIBRARY} ${NAME} ${OBJS} $(HEADER)
				@ranlib ${NAME}

clean:
				@${RM} ${OBJS}
				@${RM} ${BONUSOBJS}

fclean:		clean
				@${RM} ${NAME}

bonus:		${BONUSOBJS} ${HEADER}
				@${LIBRARY} ${NAME} ${BONUSOBJS} ${HEADER}
				@ranlib ${NAME}

re:			fclean all

.PHONY: clean all fclean re