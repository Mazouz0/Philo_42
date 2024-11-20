NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = 	philo.c \
		errors.c \
		parse.c \
		malloc.c \
		utils_1.c \
		utils_2.c \
		utils_3.c 

OBJ = $(SRC:.c=.o)

all: $(NAME)
	@echo "\nPhilo is ready to run."
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c philo.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "\nCleaned up object files."

fclean: clean
	@rm -f $(NAME)
	@echo "\nCleaned up compiled files."

re: fclean all

.PHONY: clean