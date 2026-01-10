/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhlil <mlakhlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 19:19:56 by mlakhlil          #+#    #+#             */
/*   Updated: 2025/12/23 19:19:57 by mlakhlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_data **a_stack)
{
	t_data	*first;
	t_data	*second;
	t_data	*third;

	first = *a_stack;
	second = first->next;
	third = second->next;
	if (third && (second->value > first->value && second->value > third->value))
	{
		rranb(a_stack);
		ft_printf("rra\n");
	}
	else if (third && (first->value > second->value
			&& first->value > third->value))
	{
		ranb(a_stack);
		ft_printf("ra\n");
	}
	first = *a_stack;
	second = first->next;
	if (first->value > second->value)
	{
		sanb(a_stack);
		ft_printf("sa\n");
	}
}
