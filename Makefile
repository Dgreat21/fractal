.PHONY : all re clean fclean

.SUFFIXES :
.SUFFIXES : .c .o .h .a

VPATH = .:libft:/usr/local/include:/usr/local/lib

override CC = gcc

override CFLAGS = -O2 -I. -Ilibft

MLXFLAGS = 	-I /usr/local/include \
			-L /usr/local/lib -lmlx \
			-framework OpenGL \
			-framework AppKit \

FTFLAGS = -Llibft -lft

FDFFLAGS = $(CFLAGS) $(FTFLAGS) $(MLXFLAGS)

MAKE_LIBFT = $(MAKE) -C libft

NAME = fdf

SRC =	main.c \
		debug.c \
      	draw_lines.c \
      	events.c \
      	fdf.c \
      	handler.c \
      	lines.c \
      	projection.c \
      	struct.c \
      	events_bonus.c \
      	rotation.c

OBJ = $(SRC:.c=.o)

all ::
	$(MAKE) -C libft
all :: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FDFFLAGS) $(OBJ) -o $@

clean :
	$(MAKE_LIBFT) clean
	$(RM) -f $(OBJ)

fclean : clean
	$(MAKE_LIBFT) fclean
	$(RM) -f $(NAME)

re : fclean all
