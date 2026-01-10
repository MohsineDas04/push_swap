/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_hundred_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhlil <mlakhlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 19:20:01 by mlakhlil          #+#    #+#             */
/*   Updated: 2025/12/23 19:20:01 by mlakhlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_cost(t_data **a_stack, t_data **b_stack)
{
	t_data	*track_b;
	int		b_size;
	int		a_size;
	int		target_pos;
	int		i;

	i = 0;
	b_size = ft_stack_size(*b_stack);
	a_size = ft_stack_size(*a_stack);
	track_b = *b_stack;
	while (track_b)
	{
		if (i <= b_size / 2)
			track_b->cost_b = i;
		else
			track_b->cost_b = (b_size - i) * -1;
		target_pos = ft_find_right_pos(*a_stack, track_b);
		if (target_pos <= a_size / 2)
			track_b->cost_a = target_pos;
		else
			track_b->cost_a = (a_size - target_pos) * -1;
		track_b = track_b->next;
		i++;
	}
	return (0);
}
