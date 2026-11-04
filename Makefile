NAME = fractol

CC		=	gcc
CFLAGS	=	-g #-Wall -Wextra -Werror
DEFINES	=	-DCL_SILENCE_DEPRECATION -DGL_SILENCE_DEPRECATION

INC_DIR	=	./includes/
SRC_DIR	=	./src/
SRC_LST	=	draw.c                  \
            fractal_burning_ship.c key_press.c \
            fractal_julia.c        main.c \
            fractal_mandelbrot.c   mouse.c \
            init.c                 resume_cl_init.c \
            init_cl.c              struct.c

OBJ_DIR	=	./obj/
OBJS	=	$(addprefix $(OBJ_DIR),$(SRC_LST:%.c=%.o))

LIBFT_DIR	=	./libft/
LIBFT		=	$(LIBFT_DIR)libft.a
LIBFT_HEAD	=	$(LIBFT_DIR)inc/

CMPLX_DIR	=	./libcomp/
CMPLX		=	$(CMPLX_DIR)libcomp.a
CMPLX_HEAD	=	$(CMPLX_DIR)includes/

MLX_DIR		=	./minilibx_macos/
MLX			=	$(MLX_DIR)libmlx.a

FRAMEWORKS	=	-lm -framework OpenCL -framework OpenGL -framework AppKit

INCLUDES	=	-I$(LIBFT_HEAD) -I$(INC_DIR) -I$(CMPLX_HEAD) -I$(MLX_DIR)
HEADERS		=	$(INC_DIR)fractol.h $(INC_DIR)keys.h \
				$(LIBFT_HEAD)libft.h $(LIBFT_HEAD)get_next_line.h \
				$(CMPLX_HEAD)complex.h $(MLX_DIR)mlx.h

all: $(NAME)

$(NAME): $(LIBFT) $(CMPLX) $(MLX) $(OBJS)
	$(CC) $(OBJS) $(LIBFT) $(CMPLX) $(MLX) $(FRAMEWORKS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(DEFINES) $(INCLUDES) -c $< -o $@

# Sub-makes always run and decide themselves whether their library is stale.
$(LIBFT): FORCE
	@$(MAKE) -s -C $(LIBFT_DIR)

$(CMPLX): FORCE
	@$(MAKE) -s -C $(CMPLX_DIR)

$(MLX): FORCE
	@$(MAKE) -s -C $(MLX_DIR)

FORCE:

clean:
	@$(MAKE) -s -C $(LIBFT_DIR) clean
	@$(MAKE) -s -C $(CMPLX_DIR) clean
	@$(MAKE) -s -C $(MLX_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) -s -C $(LIBFT_DIR) fclean
	@$(MAKE) -s -C $(CMPLX_DIR) fclean
	rm -f $(NAME)

re: fclean
	@$(MAKE) all

norme:
	@norminette $(LIBFT_DIR) $(INC_DIR) $(SRC_DIR)

.PHONY: all clean fclean re norme FORCE
