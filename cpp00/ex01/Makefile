CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp Contact.cpp PhoneBook.cpp
OBJS = $(SRCS:.cpp=.o)
HEADERS = PhoneBook.hpp Contact.hpp
NAME = contacts

all: $(NAME)
$(NAME): $(OBJS) $(HEADERS)
	$(CC) $(OBJS) $(CFLAGS) -o $(NAME)
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re