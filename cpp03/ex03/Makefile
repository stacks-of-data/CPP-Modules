CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -Wno-shadow
SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
OBJS = $(SRCS:.cpp=.o)
HEADERS = ClapTrap.hpp ScavTrap.hpp FragTrap.hpp DiamondTrap.hpp
NAME = DiamondTrap

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
