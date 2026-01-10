NAME        = push_swap
BONUS_NAME = checker
CC          = cc
CFLAGS      = -Wall -Wextra -Werror


LIBFT_DIR   = libft
PRINTF_DIR  = printf


LIBFT       = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

SRCS_ROOT   = push_swap.c \
		ft_abs_num.c \
		ft_cheapest_move.c \
		ft_count_nums.c \
		ft_execute.c \
		ft_find_rank.c \
		ft_find_right_pos.c \
		 ft_free_nums.c \
		ft_is_only_digit.c \
		ft_is_sorted.c \
		ft_ll_utils.c \
		ft_much_arg.c \
		ft_put_args.c \
		ft_sort_five.c \
		ft_sort_hundred.c \
		ft_sort_hundred_utils.c \
		ft_sort_three.c \
		ft_stack_size.c \
		panb.c \
		ranb.c \
		rranb.c \
		sanb.c \
		ft_dup_checker.c

SRCS_BONUS   = checker.c \
               panb.c \
              ranb.c \
              rranb.c \
              sanb.c \
              ft_count_nums.c \
              ft_execute.c \
              ft_find_rank.c \
              ft_free_nums.c \
              ft_is_only_digit.c \
              ft_is_sorted.c \
              ft_ll_utils.c \
              ft_much_arg.c \
              ft_put_args.c \
	      ft_dup_checker.c \
	      ft_stack_size.c

GNL_DIR = gnl

OBJS = $(SRCS_ROOT=.c:.o)

all: $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(PRINTF) $(LIBFT) $(SRCS_BONUS)
	$(CC) $(CFLAGS) $(SRCS_BONUS) $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c $(PRINTF) $(LIBFT) -o $(BONUS_NAME)

$(NAME): $(PRINTF) $(LIBFT) $(SRCS_ROOT)
	$(CC) $(CFLAGS) $(SRCS_ROOT) $(PRINTF) $(LIBFT) -o $(NAME)

$(PRINTF): $(SRCS_ROOT)
	make -C $(PRINTF_DIR)

$(LIBFT): $(SRCS_ROOT)
	make -C $(LIBFT_DIR)

clean: 
	make clean -C $(PRINTF_DIR) && make clean -C $(PRINTF_DIR)

fclean: 
	rm -rf push_swap checker && make fclean -C $(LIBFT_DIR) && make fclean -C $(PRINTF_DIR)

re : fclean all


.PHONY: all clean fclean re