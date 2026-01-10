/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_much_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhlil <mlakhlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 19:20:08 by mlakhlil          #+#    #+#             */
/*   Updated: 2025/12/28 17:53:36 by mlakhlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_much_arg(char *str)
{
	int	counter;

	counter = 0;
	if (!*str)
		return (0);
	while (*str)
	{
		while (*str == '-' || *str == '+')
			str++;
		if (*str >= '0' && *str <= '9')
			counter++;
		str++;
	}
	return (counter);
}
