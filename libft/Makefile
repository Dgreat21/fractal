CC = gcc

CFLAGS = -Wall -Wextra -Werror -c

SRC_FC =	*.c

SRC_FO =	*.o

NAME = libft.a

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) $(SRC_FC)
	@ar rc libft.a $(SRC_FO)

clean:
	@/bin/rm -f $(SRC_FO)

fclean: clean
	@/bin/rm -f libft.a

re: fclean all

check: re
	@/bin/rm -f $(SRC_FO)

norm:
	@norminette *.c
