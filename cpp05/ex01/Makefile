SRC   = main.cpp Bureaucrat.cpp Form.cpp
OBJ   = $(SRC:.cpp=.o)
FLAGS = -Wall -Wextra -Werror -std=c++98
NAME  = Bureaucrat

all : $(NAME)

$(NAME) : $(OBJ)
	c++ $(FLAGS) $(OBJ) -o $(NAME)

%.o:%.cpp Bureaucrat.hpp Form.hpp
	c++ $(FLAGS) -c  $< -o $@ 

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : clean 