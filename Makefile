CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS_C = src/client.c 

SRCS_S = src/server.c

OBJS_C = $(SRCS_C:.c=.o)

OBJS_S = $(SRCS_S:.c=.o)

NAME_C = client

NAME_S = server

$(NAME_S) $(NAME_C): $(OBJS_S) $(OBJS_C)
	$(CC) $(CFLAGS) $(OBJS_S) -o $(NAME_S) src/libft.a src/libftprintf.a
	$(CC) $(CFLAGS) $(OBJS_C) -o $(NAME_C) src/libft.a src/libftprintf.a

all: $(NAME_C) $(NAME_S)

clean:
	rm -f $(OBJS_C) $(OBJS_S)

fclean: clean
	rm -f $(NAME_C) $(NAME_S)

re: all fclean

.PHONY: all clean fclean re
