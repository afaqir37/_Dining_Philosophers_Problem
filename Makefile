CFLAGS = -W -W -W -pthread -fsanitize=thread
SRC = check_input.c fill_structs.c main.c ft_atoi.c \
	  supervisor.c  threading.c acts.c time.c
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