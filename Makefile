CFLAGS = -W -W -W -fsanitize=thread -pthread
SRC = check_input.c fill_structs.c main.c ft_atoi.c threading.c
OBJ = $(SRC:.c=.o)
NAME = philo
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean: 
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all