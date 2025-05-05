CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp base_utils.cpp
SRCS := $(addprefix srcs/,$(SRCS))
OBJS = $(SRCS:.cpp=.o)
HEADERS = Base.hpp A.hpp B.hpp C.hpp base_utils.hpp
HEADERS := $(addprefix includes/,$(HEADERS))
NAME = dynamic_casting

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
