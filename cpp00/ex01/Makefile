NAME = phonebook
SRC = Contact.cpp PhoneBook.cpp main.cpp
CXXFLAGS = -Wall -Wextra #-Werror -std=c++98
RM = /bin/rm -rf
OBJ = $(SRC:.cpp=.o)

$(NAME): $(OBJ)
	c++ $(OBJ) -o $(NAME)

all: $(NAME)
clean: 
	$(RM) $(OBJ)
fclean: clean 
	$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re