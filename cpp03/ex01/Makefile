SRC  = main.cpp ClapTrap.cpp ScavTrap.cpp
OBJ  = $(SRC:.cpp=.o)
FLAGS = -Wall -Wextra -Werror -std=c++98 
NAME = ClapTrap

all: $(NAME)

$(NAME) : $(OBJ)
	c++ $(FLAGS) $(OBJ) -o $(NAME)

%.o:%.cpp ClapTrap.hpp ScavTrap.hpp
	c++ $(FLAGS)  -c $< -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : clean fclean 
