/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhlil <mlakhlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:10:18 by mlakhlil          #+#    #+#             */
/*   Updated: 2025/11/05 11:59:12 by mlakhlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(const char *str, va_list my_args)
{
	if (*str == 'c')
		return (ft_printc(my_args));
	if (*str == 's')
		return (ft_prints(my_args));
	if (*str == 'p')
		return (ft_printp(my_args));
	if (*str == 'd' || *str == 'i')
		return (ft_printdec(my_args));
	if (*str == 'u')
		return (ft_printu(my_args));
	if (*str == 'x' || *str == 'X')
		return (ft_print_hex(my_args, *str));
	if (*str == '%')
		return (ft_printpercentage('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	my_args;

	count = 0;
	va_start(my_args, str);
	while (*str)
	{
		while (*str && *str != '%')
		{
			write(1, str, 1);
			str++;
			count++;
		}
		if (*str == '%')
		{
			count += ft_printchar(++str, my_args);
			str++;
		}
	}
	va_end(my_args);
	return (count);
}
