NAME = cub3d

SOURCES = main.c \
		srcs/files_getter.c \
		srcs/files_helper.c

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
		cc -o $(NAME) $(OBJECTS)

%.o: %.c
		cc -c -Wall -Wextra -Werror $< -o $(<:.c=.o) -I./headers

clean:
		rm -rf $(OBJECTS)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
