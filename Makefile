NAME = fractol

F = -g  #-Wall -Wextra -Werror

INC_DIR	=	./includes/
SRC_DIR	=	./src/
SRC_LST	=	draw.c                  \
            fractal_burning_ship.c key_press.c \
            fractal_julia.c        main.c \
            fractal_mandelbrot.c   mouse.c \
            init.c                 resume_cl_init.c \
            init_cl.c              struct.c

LIBMLX = -lmlx -lm -framework OpenGL -framework AppKit
LIBCL = -framework OpenCL
LIBFT = -L ./libft -lft
LIBCOMP = -L ./libcomp -lcomp

OBJ_DIR	=	./obj/
OBJS	=	$(addprefix $(OBJ_DIR),$(SRC_LST:%.c=%.o))

LIBFT_DIR	=	./libft/
LIBFT		=	$(LIBFT_DIR)libft.a
LIBFT_HEAD	=	$(LIBFT_DIR)inc/

CMPLX_DIR	=	./libcomp/
CMPLX		=	$(CMPLX_DIR)libcomp.a
CMPLX_HEAD	=	$(CMPLX_DIR)includes/

INCLUDES	=	-I$(LIBFT_HEAD) -I$(INC_DIR) -I$(CMPLX_HEAD)

all: $(NAME)

$(NAME): $(LIBFT) $(CMPLX) $(OBJS)
	gcc $(OBJS) $(INCLUDES) $(LIBFT) $(LIBCOMP) $(LIBCL) $(LIBMLX) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INC_DIR)
	@mkdir -p $(OBJ_DIR)
	gcc -c $(INCLUDES) -o $@ -c $<

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(CMPLX):
	make -C $(CMPLX_DIR)

clean:
	make -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re:	fclean all

norme:
	@norminette $(LIBFT_DIR) $(INC_DIR) $(SRC_DIR)

.PHONY: all clean fclean re norme