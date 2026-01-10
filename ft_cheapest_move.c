/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cheapest_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhlil <mlakhlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 19:20:34 by mlakhlil          #+#    #+#             */
/*   Updated: 2025/12/23 19:20:35 by mlakhlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cheapest_loop(t_data *tracker, int *best_val,
	int current_total_cost, int min_total_cost)
{
	int	cost_a;
	int	cost_b;

	while (tracker)
	{
		cost_a = ft_abs_num(tracker->cost_a);
		cost_b = ft_abs_num(tracker->cost_b);
		if ((tracker->cost_a > 0 && tracker->cost_b > 0)
			|| (tracker->cost_a < 0 && tracker->cost_b < 0))
		{
			if (cost_a > cost_b)
				current_total_cost = cost_a;
			else
				current_total_cost = cost_b;
		}
		else
			current_total_cost = cost_a + cost_b;
		if (current_total_cost < min_total_cost)
		{
			min_total_cost = current_total_cost;
			*best_val = tracker->value;
		}
		tracker = tracker->next;
	}
}

int	ft_cheapest_move(t_data **stack)
{
	t_data	*tracker;
	int		best_val;
	int		min_total_cost;
	int		current_total_cost;

	tracker = *stack;
	min_total_cost = 2147483647;
	current_total_cost = 0;
	if (tracker)
		best_val = tracker->value;
	cheapest_loop(tracker, &best_val, current_total_cost, min_total_cost);
	return (best_val);
}
