/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhlil <mlakhlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:49:19 by mlakhlil          #+#    #+#             */
/*   Updated: 2025/11/05 12:02:59 by mlakhlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	nums_count(int num)
{
	int	count;

	count = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		count++;
	while (num != 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

int	ft_printdec(va_list my_args)
{
	int	num;

	num = va_arg(my_args, int);
	ft_putnbr(num);
	return (nums_count(num));
}
