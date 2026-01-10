/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhlil <mlakhlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 21:59:54 by mlakhlil          #+#    #+#             */
/*   Updated: 2025/10/21 20:45:30 by mlakhlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_calc(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count++;
	}
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	if (n < 0)
		return (count + 1);
	return (count);
}

static char	*heavy_job(int len, int n, int is_negative)
{
	char	*arr;

	arr = malloc(len + 1);
	if (!arr)
		return (NULL);
	if (n < 0)
	{
		is_negative = 1;
		n *= -1;
	}
	arr[len] = '\0';
	while (len && n != 0)
	{
		arr[len - 1] = (n % 10) + 48;
		n /= 10;
		len--;
	}
	if (is_negative == 1)
		arr[0] = '-';
	return (arr);
}

char	*ft_itoa(int n)
{
	int	len;
	int	is_negative;

	is_negative = 0;
	len = len_calc(n);
	if (n == -2147483648)
	{
		return (ft_strdup("-2147483648"));
	}
	if (n == 0)
		return (ft_strdup("0"));
	return (heavy_job(len, n, is_negative));
}
