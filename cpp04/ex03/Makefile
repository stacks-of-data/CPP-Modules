CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -I./includes -g
SRCS = main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp Air.cpp Fire.cpp
SRCS := $(addprefix srcs/,$(SRCS))
OBJS = $(SRCS:.cpp=.o)
HEADERS = AMateria.hpp Character.hpp Cure.hpp ICharacter.hpp Ice.hpp IMateriaSource.hpp MateriaSource.hpp Air.hpp Fire.hpp
HEADERS := $(addprefix includes/,$(HEADERS))
NAME = Interfaces

all: $(NAME)
$(NAME): $(OBJS) $(HEADERS)
	$(CC) $(OBJS) $(CFLAGS) -o $(NAME)
%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
