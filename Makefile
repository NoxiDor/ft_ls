NAME = ft_ls

SOURCES = main.c \
		srcs/executor.c \
		srcs/sorter.c \
		srcs/displayer.c \
		srcs/files_getter.c \
		srcs/files_helper.c \
		srcs/helpers.c \

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
		cc -o $(NAME) $(OBJECTS)

%.o: %.c
		cc -c -Wall -Wextra -Werror $< -o $(<:.c=.o) -I./headers -g

clean:
		rm -rf $(OBJECTS)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
