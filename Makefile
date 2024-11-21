NAME = minitalk

SOURCES = server.c client.c
OBJECTS = $(SOURCES:%.c=%.o)
HEADER = minitalk.h

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

FT_PRINTF_DIR = ft_printf
FT_PRINTF= $(FT_PRINTF_DIR)/libftprintf.a

CFLAGS = -Wall -Wextra -Werror

all: server client

server: server.o $(LIBFT) $(FT_PRINTF)
	cc $(CFLAGS) -o server $^

client: client.o $(LIBFT) $(FT_PRINTF)
	cc $(CFLAGS) -o client $^

%.o: %.c $(HEADER)
	cc $(CFLAGS) -c $< -o $@ 

$(LIBFT):
	make -C $(LIBFT_DIR)

$(FT_PRINTF): $(LIBFT)
	make -C $(FT_PRINTF_DIR)

clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(FT_PRINTF_DIR)
	rm -f $(OBJECTS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(FT_PRINTF_DIR)
	rm -f $(NAME) server client

re: fclean all

PHONY: all server client libft ft_printf clean fclean
