NAME = smartAnimals
SRC = main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 #-fsanitize=address
LDFLAGS = -std=c++98 #-fsanitize=address
RM = /bin/rm -rf
OBJ = $(SRC:.cpp=.o)

$(NAME): $(OBJ)
	c++ $(LDFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)
clean: 
	$(RM) $(OBJ)
fclean: clean 
	$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re
