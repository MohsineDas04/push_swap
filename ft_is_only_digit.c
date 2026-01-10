/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_only_digit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhlil <mlakhlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 19:20:16 by mlakhlil          #+#    #+#             */
/*   Updated: 2025/12/28 17:42:16 by mlakhlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_only_digit(char *str)
{
	if (ft_atoi(str) > 2147483647 || ft_atoi(str) < -2147483648)
		return (0);
	while (*str)
	{
		if (*str == '-' || *str == '+')
			str++;
		if ((ft_isdigit(*str) == 0 && *str != ' '))
			return (0);
		str++;
	}
	return (1);
}
