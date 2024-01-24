CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS_C = src/client.c 

SRCS_S = src/server.c \
	 src/convert_dec.c

OBJS_C = $(SRCS_C:.c=.o)

OBJS_S = $(SRCS_S:.c=.o)

NAME_C = client

NAME_S = server

LIBFT = LIBFT/

FT_PRINTF = FT_PRINTF/

$(NAME_S) $(NAME_C): $(OBJS_S) $(OBJS_C)
	@make -C $(LIBFT)
	@make -C $(FT_PRINTF)
	@cp $(LIBFT)libft.a . && cp $(FT_PRINTF)libftprintf.a .	
	$(CC) $(CFLAGS) $(OBJS_S) -o $(NAME_S) libft.a libftprintf.a
	$(CC) $(CFLAGS) $(OBJS_C) -o $(NAME_C) libft.a libftprintf.a

all: $(NAME_C) $(NAME_S)

clean:
	rm -f $(OBJS_C) $(OBJS_S)
	@make clean -C $(FT_PRINTF)
	@make clean -C $(LIBFT)
	rm -f libft.a libftprintf.a

fclean: clean
	rm -f $(NAME_C) $(NAME_S)
	@make fclean -C $(LIBFT)
	@make fclean -C $(FT_PRINTF)

re: fclean all

.PHONY: all clean fclean re
