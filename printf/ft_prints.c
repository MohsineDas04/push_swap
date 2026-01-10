/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhlil <mlakhlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:16:48 by mlakhlil          #+#    #+#             */
/*   Updated: 2025/11/05 13:03:41 by mlakhlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_prints(va_list my_args)
{
	char	*str;
	int		count;

	count = 0;
	str = va_arg(my_args, char *);
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*str)
	{
		write(1, str, 1);
		str++;
		count++;
	}
	return (count);
}
