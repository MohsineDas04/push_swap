/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhlil <mlakhlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:52:18 by mlakhlil          #+#    #+#             */
/*   Updated: 2025/11/05 12:22:42 by mlakhlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	nums_count_u(unsigned int num)
{
	int	count;

	count = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

int	ft_printu(va_list my_args)
{
	unsigned int	num;

	num = va_arg(my_args, unsigned int);
	ft_putnbr_u(num);
	return (nums_count_u(num));
}
