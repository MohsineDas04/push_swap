/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhlil <mlakhlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 19:20:26 by mlakhlil          #+#    #+#             */
/*   Updated: 2025/12/23 19:20:27 by mlakhlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_case(int a_cost, int b_cost,
	t_data **a_stack, t_data **b_stack)
{
	while (a_cost != 0 || b_cost != 0)
	{
		if (a_cost != 0 && b_cost != 0)
		{
			rranb(a_stack);
			rranb(b_stack);
			ft_printf("rrr\n");
			a_cost++;
			b_cost++;
		}
		else if (a_cost != 0)
		{
			rranb(a_stack);
			ft_printf("rra\n");
			a_cost++;
		}
		else if (b_cost != 0)
		{
			rranb(b_stack);
			ft_printf("rrb\n");
			b_cost++;
		}
	}
}

void	second_case(int a_cost, int b_cost,
	t_data **a_stack, t_data **b_stack)
{
	while (a_cost != 0 || b_cost != 0)
	{
		if (a_cost != 0 && b_cost != 0)
		{
			ranb(a_stack);
			ranb(b_stack);
			ft_printf("rr\n");
			a_cost--;
			b_cost--;
		}
		else if (a_cost != 0)
		{
			ranb(a_stack);
			ft_printf("ra\n");
			a_cost--;
		}
		else if (b_cost != 0)
		{
			ranb(b_stack);
			ft_printf("rb\n");
			b_cost--;
		}
	}
}

void	third_first_case(int a_cost, t_data **a_stack)
{
	if (a_cost < 0)
	{
		while (a_cost++ != 0)
		{
			rranb(a_stack);
			ft_printf("rra\n");
		}
	}
	else if (a_cost > 0)
	{
		while (a_cost-- > 0)
		{
			ranb(a_stack);
			ft_printf("ra\n");
		}
	}
}

void	third_second_case(int b_cost, t_data **b_stack)
{
	if (b_cost < 0)
	{
		while (b_cost++ != 0)
		{
			rranb(b_stack);
			ft_printf("rrb\n");
		}
	}
	else if (b_cost > 0)
	{
		while (b_cost-- > 0)
		{
			ranb(b_stack);
			ft_printf("rb\n");
		}
	}
}

void	ft_execute(t_data **a_stack, t_data **b_stack, int target_num)
{
	t_data	*tracker_b;
	int		a_cost;
	int		b_cost;

	tracker_b = *b_stack;
	while (tracker_b->value != target_num)
		tracker_b = tracker_b->next;
	a_cost = tracker_b->cost_a;
	b_cost = tracker_b->cost_b;
	if (a_cost < 0 && b_cost < 0)
	{
		first_case(a_cost, b_cost, a_stack, b_stack);
	}
	else if (a_cost > 0 && b_cost > 0)
	{
		second_case(a_cost, b_cost, a_stack, b_stack);
	}
	else if (a_cost != 0 || b_cost != 0)
	{
		third_first_case(a_cost, a_stack);
		third_second_case(b_cost, b_stack);
	}
	panb(b_stack, a_stack);
	ft_printf("pa\n");
}
