
NAME		= libft.a

CC			= clang
CFLAGS		= -Wall -Werror -Wextra

HEADER		= libft.h

SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
ft_isprint.c ft_memset.c ft_strchr.c ft_strlen.c ft_strncmp.c ft_strrchr.c \
ft_tolower.c ft_toupper.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
ft_strnstr.c ft_strlcpy.c ft_strlcat.c ft_calloc.c ft_strdup.c ft_substr.c \
ft_strjoin.c ft_strtrim.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_split.c  \
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putstr_fd.c ft_putnbr_fd.c \
ft_strtjoin.c ft_strcmp.c ft_isspace.c\
./get_next_line/get_next_line.c \


OBJ		= $(SRC:%.c=%.o)

$(NAME):	$(OBJ) $(HEADER)
	ar -rcs $(NAME) $(OBJ)


all:	$(NAME)

clean:
	rm -rf $(OBJ)
	rm -rf ./a.out

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

.PHONY: all clean fclean re
