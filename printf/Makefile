NAME = libftprintf.a

SRCS = ft_printc.c ft_printf.c ft_printp.c ft_prints.c ft_putnbr_base.c ft_putnbr_u.c ft_printdec.c ft_print_hex.c ft_printpercentage.c ft_printu.c ft_putnbr.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re