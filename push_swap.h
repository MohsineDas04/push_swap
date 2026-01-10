/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhlil <mlakhlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 19:19:45 by mlakhlil          #+#    #+#             */
/*   Updated: 2025/12/24 18:22:56 by mlakhlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "printf/ft_printf.h"

typedef struct s_data
{
	int				value;
	int				rank;
	int				cost_a;
	int				cost_b;
	struct s_data	*prev;
	struct s_data	*next;
}	t_data;

/*
** Argument Processing & Setup
*/
int		ft_is_only_digit(char *str);
int		ft_much_arg(char *str);
int		*ft_put_args(int argc, char **argv, int *arr);
int		count_nums(int argc, char **argv);
int		ft_find_rank(int *arr, int num, int size);
int		ft_is_sorted(int *arr, int allsize);
void	free_nums(char **nums);
int		ft_loop_counter(int argc,
			char **argv, int counter);
int		ft_loop_insider(char **argv, int i, int j, int counter);
void	ft_loop(int j, int argc, char **argv, int *arr);
int		ft_dup_check(int *arr, int all_size);
/*
** Linked List Utils
*/
t_data	*ft_put_to_struct(int *arr, int size);
t_data	*ft_put_node(int num, int rank);
void	ft_put_last(t_data **stack, t_data *node);
t_data	*create_stack_b(void);
void	free_ll(t_data **head);

/*
** Operations (Moves)
*/
void	sanb(t_data **head);
void	panb(t_data **a_stack, t_data **b_stack);
void	ranb(t_data **head);
void	rranb(t_data **head);

/*
** Sorting Algorithms
*/
void	ft_decide(int *arr, int allsize);
void	ft_sort_three(t_data **a_stack);
void	ft_sort_five(t_data **a_stack, t_data **b_stack, int allsize);
void	ft_sort_hundred(t_data **a_stack, t_data **b_stack, int allsize);
/*
** Sort Utils (Five)
*/
int		find_pos(t_data **stack, int target_rank, int *value);
int		is_in_position(t_data **a_stack, int target, int target_pos);
void	put_to_top(t_data **stack, int target, int value, char direction);
void	ft_sort_job(t_data **a_stack, t_data **b_stack,
			int rank_target, int len);
int		ft_find_right_pos(t_data *a_stack, t_data *b_stack);
int		ft_cost(t_data **a_stack, t_data **b_stack);
int		ft_cheapest_move(t_data **stack);
int		ft_abs_num(int num);
void	ft_execute(t_data **a_stack, t_data **b_stack, int target_num);
int		ft_min(t_data **stack);
void	ft_last_move(t_data **a_stack);
void	cheapest_loop(t_data *tracker, int *best_val,
			int current_total_cost, int min_total_cost);
void	first_case(int a_cost, int b_cost, t_data **a_stack, t_data **b_stack);
void	second_case(int a_cost, int b_cost, t_data **a_stack, t_data **b_stack);
void	third_first_case(int a_cost, t_data **a_stack);
void	third_second_case(int b_cost, t_data **b_stack);

/*
** Printing UTILS
*/
int		ft_stack_size(t_data *stack);
#endif