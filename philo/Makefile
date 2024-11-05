NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread -g

SRC = 	philo.c \
		 \
		 \
		 \
		 \
		 \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c philo.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean