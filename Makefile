NAME = test
FLAGS = -g -Wall -Wextra -Werror

all: $(NAME)

$(NAME): test.c
	cc $(FLAGS) test.c -o $(NAME)

run: $(NAME)
	./$(NAME)

dbg: $(NAME)
	gdb ./$(NAME)
