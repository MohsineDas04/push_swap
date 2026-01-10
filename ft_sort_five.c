/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhlil <mlakhlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 19:20:03 by mlakhlil          #+#    #+#             */
/*   Updated: 2025/12/23 19:20:03 by mlakhlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_pos(t_data **stack, int target_rank, int *value)
{
	t_data	*tracker;
	int		i;

	tracker = *stack;
	i = 0;
	while (tracker)
	{
		if (target_rank == tracker->rank)
		{
			*value = tracker->value;
			return (i);
		}
		tracker = tracker->next;
		i++;
	}
	return (-1);
}

int	is_in_position(t_data **a_stack, int target, int target_pos)
{
	t_data	*tracker;
	int		i;

	i = 0;
	tracker = *a_stack;
	while (tracker)
	{
		if (tracker->value == target)
		{
			if (i == target_pos)
				return (1);
			else
				return (0);
		}
		tracker = tracker->next;
		i++;
	}
	return (-1);
}

void	put_to_top(t_data **stack, int target, int value, char direction)
{
	while (is_in_position(stack, value, target) == 0)
	{
		if (direction == 'r')
		{
			rranb(stack);
			ft_printf("rra\n");
		}
		if (direction == 'f')
		{
			ranb(stack);
			ft_printf("ra\n");
		}
	}
}

void	ft_sort_job(t_data **a_stack, t_data **b_stack,
	int rank_target, int len)
{
	int	position;
	int	value;

	position = find_pos(a_stack, rank_target, &value);
	if (position == -1)
		return ;
	else if (position == 0)
		return (panb(a_stack, b_stack), (void)ft_printf("pb\n"));
	else if (position == len)
		return (rranb(a_stack), panb(a_stack, b_stack),
			(void)ft_printf("pb\n"));
	else if (position > 3)
		return (put_to_top(a_stack, 0, value, 'r'), panb(a_stack, b_stack),
			(void)ft_printf("pb\n"));
	else if (position <= 3)
		return (put_to_top(a_stack, 0, value, 'f'), panb(a_stack, b_stack),
			(void)ft_printf("pb\n"));
}

void	ft_sort_five(t_data **a_stack, t_data **b_stack, int allsize)
{
	(void)allsize;
	if (allsize == 5)
	{
		ft_sort_job(a_stack, b_stack, 0, 5);
		ft_sort_job(a_stack, b_stack, 1, 4);
		ft_sort_three(a_stack);
		panb(b_stack, a_stack);
		panb(b_stack, a_stack);
		ft_printf("pa\npa\n");
	}
	else
	{
		ft_sort_job(a_stack, b_stack, 0, 5);
		ft_sort_three(a_stack);
		panb(b_stack, a_stack);
		ft_printf("pa\n");
	}
}
