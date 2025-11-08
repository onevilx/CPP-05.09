NAME = Form
CC = c++
RM = rm -f
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
SOURCES = main.cpp Bureaucrat.cpp Form.cpp
INCLUDES = Bureaucrat.hpp Form.hpp

OBJ = $(SOURCES:.cpp=.opp)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $@

%.opp: %.cpp $(INCLUDES)
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)	

fclean: clean
	$(RM) $(NAME)

re: fclean all