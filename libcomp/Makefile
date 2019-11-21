NAME = libcomp.a

INC_DIR		= ./includes
SRC_DIR		= ./src
OBJ_DIR		= ./obj

HEAD		= $(INC_DIR)/complex.h

SRC			= abs.c\
              cmplx_hard_math.c\
              cmplx_simple_operation.c\
              set_num.c\

OBJS	=	$(addprefix $(OBJ_DIR)/,$(SRC:%.c=%.o))

$(NAME): $(OBJ_DIR) $(OBJS) $(HEAD)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@gcc $F -g -c $< -I$(INC_DIR) -o$@

clean:
	@rm -Rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

norm:
	@norminette $(SRC_DIR) $(INC_DIR)

.PHONY: all clean fclean re norm