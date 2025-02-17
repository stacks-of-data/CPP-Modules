CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -I./includes
SRCS = main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp
SRCS := $(addprefix srcs/,$(SRCS))
OBJS = $(SRCS:.cpp=.o)
HEADERS = AMateria.hpp Character.hpp Cure.hpp ICharacter.hpp Ice.hpp IMateriaSource.hpp
HEADERS := $(addprefix includes/,$(HEADERS))
NAME = Interfaces

all: $(NAME)
$(NAME): $(OBJS) $(HEADERS)
	$(CC) $(OBJS) $(CFLAGS) -o $(NAME)
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
