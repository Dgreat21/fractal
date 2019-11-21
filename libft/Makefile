NAME = libft.a

INC_DIR		= ./inc
SRC_DIR		= ./src
OBJ_DIR		= ./obj

HEAD		= $(INC_DIR)/libft.h

SRC			= endl.c            ft_memchr.c       ft_striter.c \
              error_notice.c    ft_memcmp.c       ft_striteri.c \
              fract.c           ft_memcpy.c       ft_strjoin.c \
              free_str.c        ft_memdel.c       ft_strlcat.c \
              ft_atoi.c         ft_memmove.c      ft_strlen.c \
              ft_atoi_base.c    ft_memset.c       ft_strmap.c \
              ft_bzero.c        ft_pow_uint.c     ft_strmapi.c \
              ft_fswap.c        ft_putchar.c      ft_strmlen.c \
              ft_isalnum.c      ft_putchar_fd.c   ft_strncat.c \
              ft_isalpha.c      ft_putendl.c      ft_strncmp.c \
              ft_isascii.c      ft_putendl_fd.c   ft_strncpy.c \
              ft_isdigit.c      ft_putnbr.c       ft_strnequ.c \
              ft_isprint.c      ft_putnbr_base.c  ft_strnew.c \
              ft_iswhitespace.c ft_putnbr_fd.c    ft_strnstr.c \
              ft_itoa.c         ft_putstr.c       ft_strrchr.c \
              ft_itoa_base.c    ft_putstr_fd.c    ft_strsplit.c \
              ft_ldel.c         ft_realloc.c      ft_strstr.c \
              ft_log.c          ft_strcat.c       ft_strsub.c \
              ft_lst_clear.c    ft_strchr.c       ft_strtrim.c \
              ft_lstadd.c       ft_strchr_safe.c  ft_swap.c \
              ft_lstadd_end.c   ft_strclr.c       ft_tolower.c \
              ft_lstdel.c       ft_strcmp.c       ft_toupper.c \
              ft_lstdelone.c    ft_strcpy.c       ft_word_counter.c \
              ft_lstiter.c      ft_strcpy_safe.c  get_next_line.c \
              ft_lstmap.c       ft_strdel.c       min_max.c \
              ft_lstnew.c       ft_strdup.c       read_file.c \
              ft_memalloc.c     ft_strdup_safe.c  vardump.c \
              ft_memccpy.c      ft_strequ.c  \

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