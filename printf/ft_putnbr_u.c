/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhlil <mlakhlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 15:26:25 by mlakhlil          #+#    #+#             */
/*   Updated: 2025/11/04 06:45:40 by mlakhlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_u(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_u(unsigned int nb)
{
	if (nb > 9)
	{
		ft_putnbr_u(nb / 10);
		ft_putnbr_u(nb % 10);
	}
	else
	{
		ft_putchar_u(nb + 48);
	}
}
