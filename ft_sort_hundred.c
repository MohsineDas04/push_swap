/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_hundred.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhlil <mlakhlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 19:19:58 by mlakhlil          #+#    #+#             */
/*   Updated: 2025/12/23 19:19:58 by mlakhlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_calculate_av(t_data	*stack)
{
	long long	total;
	long long	times;

	total = 0;
	times = 0;
	while (stack)
	{
		total += stack->value;
		times++;
		stack = stack->next;
	}
	return (total / times);
}

int	get_current_value(t_data *stack)
{
	return (stack->value);
}

int	ft_min(t_data **stack)
{
	t_data	*tracker;
	int		min;
	int		position;
	int		i;

	tracker = *stack;
	min = 2147483647;
	i = 0;
	while (tracker)
	{
		if (tracker->value < min)
		{
			min = tracker->value;
			position = i;
		}
		tracker = tracker->next;
		i++;
	}
	return (position);
}

void	ft_last_move(t_data **a_stack)
{
	int	ll_size;
	int	position;

	ll_size = ft_stack_size(*a_stack);
	position = ft_min(a_stack);
	if (position <= ll_size / 2)
	{
		while (position-- > 0)
		{
			ranb(a_stack);
			ft_printf("ra\n");
		}
	}
	else if (position > ll_size / 2)
	{
		position = (ll_size - position) * -1;
		while (position++ != 0)
		{
			rranb(a_stack);
			ft_printf("rra\n");
		}
	}
}

void	ft_sort_hundred(t_data **a_stack, t_data **b_stack, int allsize)
{
	int			target;
	long long	average;

	average = ft_calculate_av(*a_stack);
	while (allsize > 3)
	{
		panb(a_stack, b_stack);
		ft_printf("pb\n");
		if ((*b_stack)->value < average && ft_stack_size(*b_stack) > 1)
		{
			ranb(b_stack);
			ft_printf("rb\n");
		}
		allsize--;
		if (allsize == ft_stack_size(*a_stack) / 2)
			average = ft_calculate_av(*a_stack);
	}
	ft_sort_three(a_stack);
	while (*b_stack)
	{
		ft_cost(a_stack, b_stack);
		target = ft_cheapest_move(b_stack);
		ft_execute(a_stack, b_stack, target);
	}
	ft_last_move(a_stack);
}
