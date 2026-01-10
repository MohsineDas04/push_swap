/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhlil <mlakhlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 15:16:55 by mlakhlil          #+#    #+#             */
/*   Updated: 2025/12/25 15:41:44 by mlakhlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_put_and_check(t_data *a_stack, t_data *b_stack, int allsize)
{
	int	*arr;
	int	*svstate;

	arr = malloc((allsize + 1) * sizeof(int));
	if (!arr)
		return ;
	svstate = arr;
	while (a_stack)
	{
		*svstate = a_stack->value;
		a_stack = a_stack->next;
		svstate++;
	}
	if (!b_stack && ft_is_sorted(arr, allsize) == 1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free(arr);
}

void	ft_ins_exe(char *ins, t_data **a_stack, t_data **b_stack)
{
	if (ft_strncmp(ins, "sa\n", 3) == 0)
		return (sanb(a_stack));
	else if (ft_strncmp(ins, "sb\n", 3) == 0)
		return (sanb(b_stack));
	else if (ft_strncmp(ins, "ss\n", 3) == 0)
		return (sanb(a_stack), sanb(b_stack));
	else if (ft_strncmp(ins, "pa\n", 3) == 0)
		return (panb(b_stack, a_stack));
	else if (ft_strncmp(ins, "pb\n", 3) == 0)
		return (panb(a_stack, b_stack));
	else if (ft_strncmp(ins, "ra\n", 3) == 0)
		return (ranb(a_stack));
	else if (ft_strncmp(ins, "rb\n", 3) == 0)
		return (ranb(b_stack));
	else if (ft_strncmp(ins, "rr\n", 3) == 0)
		return (ranb(a_stack), ranb(b_stack));
	else if (ft_strncmp(ins, "rra\n", 4) == 0)
		return (rranb(a_stack));
	else if (ft_strncmp(ins, "rrb\n", 4) == 0)
		return (rranb(b_stack));
	else if (ft_strncmp(ins, "rrr\n", 4) == 0)
		return (rranb(a_stack), rranb(b_stack));
	else
		return ((void)write(1, "Error\n", 6), exit(1));
}

void	ft_check_exe(int *arr, int allsize)
{
	t_data	*stack_a;
	t_data	*stack_b;
	char	*instruction;

	stack_a = ft_put_to_struct(arr, allsize);
	if (!stack_a)
		return (free(arr), free_ll(&stack_a),
			(void)write(2, "Error\n", 6));
	stack_b = NULL;
	instruction = get_next_line(0);
	while (instruction)
	{
		ft_ins_exe(instruction, &stack_a, &stack_b);
		free(instruction);
		instruction = get_next_line(0);
	}
	ft_put_and_check(stack_a, stack_b, allsize);
	return (free(arr), free_ll(&stack_a), free_ll(&stack_b));
}

int	main(int argc, char *argv[])
{
	int	*arr;
	int	allsize;

	if (argc < 2)
		return (0);
	allsize = 0;
	allsize = count_nums(argc, argv);
	if (allsize < 1)
		return (0);
	else if (allsize > 2147483647)
		return ((void)(write(2, "Error\n", 5)), 0);
	arr = malloc(allsize * sizeof(int));
	if (!arr)
		return (0);
	ft_put_args(argc, argv, arr);
	if (ft_dup_check(arr, allsize) == 1)
		return (free(arr), write(2, "Error\n", 6), 0);
	ft_check_exe(arr, allsize);
	return (0);
}
