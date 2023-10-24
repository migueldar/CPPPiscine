NAME = serialize
SRC = main.cpp Serializer.cpp Data.cpp
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
LDFLAGS = -std=c++98
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
