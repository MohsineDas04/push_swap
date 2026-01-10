/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhlil <mlakhlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 06:45:16 by mlakhlil          #+#    #+#             */
/*   Updated: 2025/11/05 12:19:43 by mlakhlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	num_len(unsigned long long num)
{
	int	count;

	count = 0;
	while (num != 0)
	{
		num /= 16;
		count++;
	}
	return (count);
}

int	ft_printp(va_list my_args)
{
	char				*base;
	unsigned long long	p;
	int					counter;

	base = "0123456789abcdef";
	p = (unsigned long long)va_arg(my_args, void *);
	counter = 0;
	if (p == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	counter += 2;
	ft_putnbr_base((unsigned long long)p, base);
	return (counter + num_len(p));
}
