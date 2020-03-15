NAME = bsq

SRCS = srcs/*.c

OBJECTS = *.o

HEADERS = includes

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@gcc -c $(SRCS) -I $(HEADERS)
	@gcc $(FLAGS) -o $(NAME) $(OBJECTS)

clean:
	@rm $(OBJECTS)

fclean: clean
	@rm $(NAME)

re: fclean all
