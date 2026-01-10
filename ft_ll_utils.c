/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ll_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhlil <mlakhlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 19:20:10 by mlakhlil          #+#    #+#             */
/*   Updated: 2025/12/23 19:20:11 by mlakhlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_put_last(t_data **stack, t_data *node)
{
	t_data	*walker;

	if (!stack)
		return ;
	if (!*stack)
	{
		*stack = node;
		node->prev = NULL;
		node->next = NULL;
		return ;
	}
	walker = *stack;
	while (walker->next != NULL)
		walker = walker->next;
	walker->next = node;
	node->prev = walker;
}

t_data	*ft_put_node(int num, int rank)
{
	t_data	*new_node;

	new_node = malloc(sizeof(t_data));
	if (!new_node)
		return (NULL);
	new_node->value = num;
	new_node->rank = rank;
	new_node->cost_a = -1;
	new_node->cost_b = -1;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

t_data	*ft_put_to_struct(int *arr, int size)
{
	t_data	*head;
	t_data	*node;
	int		rank;
	int		i;

	rank = 0;
	head = NULL;
	i = 0;
	while (i < size)
	{
		rank = ft_find_rank(arr, arr[i], size);
		if (rank == 999999)
			return (NULL);
		node = ft_put_node(arr[i], rank);
		ft_put_last(&head, node);
		i++;
	}
	return (head);
}

t_data	*create_stack_b(void)
{
	t_data	*head;

	head = NULL;
	return (head);
}

void	free_ll(t_data **head)
{
	t_data	*track;
	t_data	*next;

	track = *head;
	while (track)
	{
		next = track->next;
		free(track);
		track = next;
	}
}
