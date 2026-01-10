/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rranb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhlil <mlakhlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 19:19:40 by mlakhlil          #+#    #+#             */
/*   Updated: 2025/12/23 19:19:41 by mlakhlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rranb(t_data **head)
{
	t_data	*first;
	t_data	*b_last;
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
	b_last = end_finder->prev;
	last = end_finder;
	last->next = first;
	last->prev = NULL;
	first->prev = last;
	b_last->next = NULL;
	*head = last;
}
