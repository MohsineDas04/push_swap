/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhlil <mlakhlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 06:45:58 by mlakhlil          #+#    #+#             */
/*   Updated: 2025/11/05 12:23:44 by mlakhlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned long long nb, const char *base)
{
	char	tp;

	if (nb > 15)
	{
		ft_putnbr_base(nb / 16, base);
		ft_putnbr_base(nb % 16, base);
	}
	else
	{
		tp = base[nb];
		write(1, &tp, 1);
	}
}
