NAME = libft.a

OBJECTS = ft_atoi.o ft_bzero.o ft_calloc.o ft_isalnum.o ft_isalpha.o \
          ft_isascii.o ft_isdigit.o ft_isprint.o ft_itoa.o ft_memchr.o \
          ft_memcmp.o ft_memmove.o ft_memset.o ft_putchar_fd.o ft_putendl_fd.o \
          ft_putnbr_fd.o ft_putstr_fd.o ft_split.o ft_strchr.o ft_strdup.o \
          ft_striteri.o ft_strjoin.o ft_strlcat.o ft_strlcpy.o ft_strlen.o \
          ft_strmapi.o ft_strncmp.o ft_strnstr.o ft_strrchr.o ft_strtrim.o \
          ft_substr.o ft_tolower.o ft_toupper.o ft_memcpy.o ft_printf.o \
		  ft_printf_hex.o ft_printf_nbr.o ft_swap.o get_next_line.o ft_strjoin_free.o

CC = @cc

CFLAGS = -Wall -Wextra -Werror

RM = @rm -f

$(NAME)	: $(OBJECTS) libft.h
	@ar -rc $(NAME) $(OBJECTS)

all : $(NAME)

clean :
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean
	@make

.PHONY: all clean fclean re