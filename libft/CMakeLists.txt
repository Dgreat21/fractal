cmake_minimum_required(VERSION 3.0)

cmake_policy(SET CMP0076 NEW)

project(LIBFT VERSION 1.0 LANGUAGES C)

set(sources
        src/endl.c
        src/error_notice.c
        src/fract.c
        src/free_str.c
        src/ft_atoi.c
        src/ft_atoi_base.c
        src/ft_bzero.c
        src/ft_fswap.c
        src/ft_isalnum.c
        src/ft_isalpha.c
        src/ft_isascii.c
        src/ft_isdigit.c
        src/ft_isprint.c
        src/ft_iswhitespace.c
        src/ft_itoa.c
        src/ft_itoa_base.c
        src/ft_ldel.c
        src/ft_log.c
        src/ft_lst_clear.c
        src/ft_lstadd.c
        src/ft_lstadd_end.c
        src/ft_lstdel.c
        src/ft_lstdelone.c
        src/ft_lstiter.c
        src/ft_lstmap.c
        src/ft_lstnew.c
        src/ft_memalloc.c
        src/ft_memccpy.c
        src/ft_memchr.c
        src/ft_memcmp.c
        src/ft_memcpy.c
        src/ft_memdel.c
        src/ft_memmove.c
        src/ft_memset.c
        src/ft_pow_uint.c
        src/ft_putchar.c
        src/ft_putchar_fd.c
        src/ft_putendl.c
        src/ft_putendl_fd.c
        src/ft_putnbr.c
        src/ft_putnbr_base.c
        src/ft_putnbr_fd.c
        src/ft_putstr.c
        src/ft_putstr_fd.c
        src/ft_realloc.c
        src/ft_strcat.c
        src/ft_strchr.c
        src/ft_strchr_safe.c
        src/ft_strclr.c
        src/ft_strcmp.c
        src/ft_strcpy.c
        src/ft_strcpy_safe.c
        src/ft_strdel.c
        src/ft_strdup.c
        src/ft_strdup_safe.c
        src/ft_strequ.c
        src/ft_striter.c
        src/ft_striteri.c
        src/ft_strjoin.c
        src/ft_strlcat.c
        src/ft_strlen.c
        src/ft_strmap.c
        src/ft_strmapi.c
        src/ft_strmlen.c
        src/ft_strncat.c
        src/ft_strncmp.c
        src/ft_strncpy.c
        src/ft_strnequ.c
        src/ft_strnew.c
        src/ft_strnstr.c
        src/ft_strrchr.c
        src/ft_strsplit.c
        src/ft_strstr.c
        src/ft_strsub.c
        src/ft_strtrim.c
        src/ft_swap.c
        src/ft_tolower.c
        src/ft_toupper.c
        src/ft_word_counter.c
        src/get_next_line.c
        src/min_max.c
        src/vardump.c)

include_directories(inc)

add_library(ft STATIC
        ${sources})