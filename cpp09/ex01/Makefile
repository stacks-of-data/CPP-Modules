CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g
SRCS = main.cpp RPN.cpp
SRCS := $(addprefix srcs/,$(SRCS))
OBJS = $(SRCS:.cpp=.o)
HEADERS = RPN.hpp
HEADERS := $(addprefix includes/,$(HEADERS))
NAME = RPN

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
