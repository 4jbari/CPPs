SRC  = main.cpp Fixed.cpp Point.cpp bsp.cpp
OBJ  = $(SRC:.cpp=.o)
FLAGS = -Wall -Wextra -Werror -std=c++98 
NAME = fixed-point

all: $(NAME)

$(NAME) : $(OBJ)
	c++ $(FLAGS) $(OBJ) -o $(NAME)

%.o:%.cpp Fixed.hpp Point.hpp
	c++ $(FLAGS)  -c $< -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : clean fclean 
