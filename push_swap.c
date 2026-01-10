/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhlil <mlakhlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 19:19:48 by mlakhlil          #+#    #+#             */
/*   Updated: 2025/12/28 17:52:37 by mlakhlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_decide(int *arr, int allsize)
{
	t_data	*stack_a;
	t_data	*stack_b;

	if (ft_is_sorted(arr, allsize) == 1)
		return (free(arr));
	stack_a = ft_put_to_struct(arr, allsize);
	if (!stack_a)
		return (free(arr), free_ll(&stack_a),
			(void)write(2, "Error\n", 6));
	stack_b = create_stack_b();
	if (allsize <= 3)
		ft_sort_three(&stack_a);
	else if (allsize <= 5)
		ft_sort_five(&stack_a, &stack_b, allsize);
	else
		ft_sort_hundred(&stack_a, &stack_b, allsize);
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
	if (allsize == 0)
		return (0);
	else if (allsize < 2)
		return (0);
	arr = malloc(allsize * sizeof(int));
	if (!arr)
		return (0);
	ft_put_args(argc, argv, arr);
	if (ft_dup_check(arr, allsize) == 1)
		return (free(arr), write(2, "Error\n", 6), 0);
	ft_decide(arr, allsize);
	return (0);
}
