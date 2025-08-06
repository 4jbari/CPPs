SRC 	= main.cpp Serializer.cpp
OBJ 	= $(SRC:.cpp=.o) 

FLAGS 	= -Wall -Wextra -Werror -std=c++98

NAME = Serializer

all : $(NAME)

$(NAME) : $(OBJ)
	c++ $(FLAGS) $(OBJ) -o $(NAME)


%.o:%.cpp Serializer.hpp Data.hpp
	c++ $(FLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all 

.PHONY: clean