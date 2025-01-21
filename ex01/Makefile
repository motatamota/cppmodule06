NAME = ex01
FLAG = -Wall -Wextra -Werror
SRC = main.cpp Serializer.cpp
OBJ = $(SRC:.cpp=.o)
CC = g++

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAG) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CC) $(FLAG) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

