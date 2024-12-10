SRCS = exit.c init.c eat.c monitoring.c sleep.c start.c stop.c think.c
UTIL = libft.c utils.c
APP = ./app/philosophers.c
CFLAGS = -Wall -Wextra -Werror -pthread -fsanitize=thread -g3
OBJ_DIR = ./obj
DIR_UTIL	= ./util/
DIR_SRC = ./src/
NAME = philo
SRC_OBJ = $(SRCS:%.c=$(OBJ_DIR)/%.o)
UTIL_OBJ =  $(UTIL:%.c=$(OBJ_DIR)/%.o)
OBJS = $(SRC_OBJ) $(UTIL_OBJ)

vpath %.c $(DIR_SRC) $(DIR_UTIL)

all: $(NAME)

$(NAME): $(APP) $(OBJ_DIR) $(OBJS)
	@cc $(CFLAGS) $(APP) $(OBJS) -o $(NAME)

$(OBJ_DIR):
	@mkdir -p ${OBJ_DIR}

$(OBJ_DIR)/%.o: %.c
	@/bin/echo -n .
	@cc $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo "obj limpos"
fclean: clean
	@rm -rf $(NAME)
	@echo "$(NAME) limpo"

re: fclean all


