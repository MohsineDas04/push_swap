/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhlil <mlakhlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:34:33 by mlakhlil          #+#    #+#             */
/*   Updated: 2025/11/05 14:57:22 by mlakhlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printc(va_list my_args)
{
	char	char_tp;

	char_tp = va_arg(my_args, int);
	write(1, &char_tp, 1);
	return (1);
}
