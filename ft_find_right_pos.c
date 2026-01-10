/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_right_pos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhlil <mlakhlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 19:20:21 by mlakhlil          #+#    #+#             */
/*   Updated: 2025/12/23 19:20:21 by mlakhlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_min_pos(t_data *stack)
{
	int	i;
	int	min_val;
	int	min_idx;

	i = 0;
	min_val = 2147483647;
	min_idx = 0;
	while (stack)
	{
		if (stack->value < min_val)
		{
			min_val = stack->value;
			min_idx = i;
		}
		stack = stack->next;
		i++;
	}
	return (min_idx);
}

int	ft_find_right_pos(t_data *a_stack, t_data *b_stack)
{
	t_data	*current;
	int		i;
	int		best;
	int		target;

	i = 0;
	best = 2147483647;
	target = -1;
	current = a_stack;
	while (current)
	{
		if (current->value > b_stack->value && current->value < best)
		{
			best = current->value;
			target = i;
		}
		current = current->next;
		i++;
	}
	if (target == -1)
		return (ft_find_min_pos(a_stack));
	return (target);
}
