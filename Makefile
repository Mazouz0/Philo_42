NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread 

SRC = 	philo.c \
		errors.c \
		parse.c \
		malloc.c \
		utils_1.c \
		utils_2.c \
		utils_3.c \
		 \
		 \
		 \

OBJ = $(SRC:.c=.o)

all: $(NAME)
	@echo "\nPhilo is ready to run.\n"
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c philo.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "\nCleaned up object files.\n"

fclean: clean
	@rm -f $(NAME)
	@echo "\nCleaned up compiled files.\n"

re: fclean all

.PHONY: clean