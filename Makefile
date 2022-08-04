CC = clang++

CFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -rf

SRCS = $(wildcard testing/*.cpp)

HDRS =

OBJS = $(SRCS:.cpp=.o)

NAME = test

$(NAME):	$(OBJS) $(HDRS)
	$(CC) $(OBJS) -o $@

%.o:	%.cpp
	$(CC) -c $(CFLAGS) $< -o $@ 

all:	$(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re