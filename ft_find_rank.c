/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_rank.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhlil <mlakhlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 19:20:23 by mlakhlil          #+#    #+#             */
/*   Updated: 2025/12/23 19:20:24 by mlakhlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_rank(int *arr, int num, int size)
{
	int	rank;
	int	dup_check;

	rank = 0;
	dup_check = 0;
	while (size--)
	{
		if (num == *arr)
			dup_check++;
		if (num > *arr)
			rank++;
		arr++;
	}
	if (dup_check > 1)
		return (999999);
	return (rank);
}
