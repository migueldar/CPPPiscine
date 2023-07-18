NAME = horde
SRC = main.cpp Zombie.cpp zombieHorde.cpp
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address
RM = /bin/rm -rf
OBJ = $(SRC:.cpp=.o)


$(NAME): $(OBJ)
	c++ -fsanitize=address $(OBJ) -o $(NAME)

all: $(NAME)
clean: 
	$(RM) $(OBJ)
fclean: clean 
	$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re
