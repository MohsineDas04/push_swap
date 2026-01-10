/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhlil <mlakhlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 19:19:51 by mlakhlil          #+#    #+#             */
/*   Updated: 2025/12/23 19:19:52 by mlakhlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	panb(t_data **a_stack, t_data **b_stack)
{
	t_data	*fa_node;
	t_data	*sa_node;
	t_data	*fb_node;

	fa_node = *a_stack;
	sa_node = fa_node->next;
	if (sa_node != NULL)
	{
		*a_stack = sa_node;
		sa_node->prev = NULL;
	}
	else
		*a_stack = NULL;
	fb_node = *b_stack;
	if (fb_node != NULL)
		fb_node->prev = fa_node;
	if (fb_node != NULL)
		fa_node->next = fb_node;
	else
	{
		fa_node->next = NULL;
		fa_node->prev = NULL;
	}
	*b_stack = fa_node;
}
