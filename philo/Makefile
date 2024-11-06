NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread -g -fsanitize=address

SRC = 	philo.c \
		errors.c \
		parse.c \
		parse_utils.c \
		 \
		 \
		 \
		 \
		 \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c philo.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "Cleaned up object files."

fclean: clean
	@rm -f $(NAME)
	@echo "Cleaned up compiled files."

re: fclean all
	@echo "Recompiled all files."

.PHONY: clean