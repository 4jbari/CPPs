SRC = tests.cpp Account.cpp
OBJ = $(SRC:.cpp=.o)
FLAGS = -Wall -Wextra -Werror -std=c++98 
NAME = log

all : $(NAME) 

$(NAME) : $(OBJ) 
	c++ $(FLAGS) $(OBJ) -o $(NAME)

%.o:%.cpp Account.hpp
	c++  $(FLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: clean re fclean 
