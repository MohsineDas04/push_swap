/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhlil <mlakhlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 19:20:13 by mlakhlil          #+#    #+#             */
/*   Updated: 2025/12/23 19:20:14 by mlakhlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(int *arr, int allsize)
{
	int	i;

	i = 0;
	while (i < allsize - 1)
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}
