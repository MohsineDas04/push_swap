/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhlil <mlakhlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 07:43:29 by mlakhlil          #+#    #+#             */
/*   Updated: 2025/11/05 11:54:44 by mlakhlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	num_len_hex(unsigned long long num)
{
	int	count;

	count = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num /= 16;
		count++;
	}
	return (count);
}

int	ft_print_hex(va_list my_args, char type)
{
	unsigned int	p;

	p = (unsigned long long)va_arg(my_args, unsigned int);
	if (type == 'x')
		ft_putnbr_base(p, "0123456789abcdef");
	else if (type == 'X')
		ft_putnbr_base(p, "0123456789ABCDEF");
	return (num_len_hex(p));
}
