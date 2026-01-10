/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ranb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhlil <mlakhlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 19:19:43 by mlakhlil          #+#    #+#             */
/*   Updated: 2025/12/23 19:19:44 by mlakhlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ranb(t_data **head)
{
	t_data	*first;
	t_data	*second;
	t_data	*last;
	t_data	*end_finder;

	if (!head || !*head)
		return ;
	end_finder = *head;
	if (end_finder->next == NULL )
		return ;
	while (end_finder->next != NULL)
		end_finder = end_finder->next;
	first = *head;
	second = first->next;
	last = end_finder;
	first->next = NULL;
	first->prev = last;
	second->prev = NULL;
	last->next = first;
	*head = second;
}
