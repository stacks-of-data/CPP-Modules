CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = Account.cpp tests.cpp
OBJS = $(SRCS:.cpp=.o)
HEADERS = Account.hpp
NAME = accounts_manager

all: $(NAME)
$(NAME): $(OBJS) $(HEADERS)
	$(CC) $(OBJS) $(CFLAGS) -o $(NAME)
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re