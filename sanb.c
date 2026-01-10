/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sanb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhlil <mlakhlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 19:19:37 by mlakhlil          #+#    #+#             */
/*   Updated: 2025/12/23 19:19:38 by mlakhlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sanb(t_data **head)
{
	t_data	*first;
	t_data	*second;
	t_data	*third;
	t_data	*tracker;
	int		i;

	tracker = *head;
	i = ft_stack_size(tracker);
	first = *head;
	second = first->next;
	if (i > 2)
		third = second->next;
	first->prev = second;
	second->prev = NULL;
	second->next = first;
	if (i > 2)
	{
		first->next = third;
		third->prev = first;
	}
	else
		first->next = NULL;
	*head = second;
}
