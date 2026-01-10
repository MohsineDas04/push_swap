/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhlil <mlakhlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 21:20:50 by mlakhlil          #+#    #+#             */
/*   Updated: 2025/10/15 09:28:12 by mlakhlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*alts1;
	unsigned char	*alts2;

	alts1 = (unsigned char *)s1;
	alts2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (n > 0)
	{
		if (*alts1 != *alts2)
			return (*alts1 - *alts2);
		alts1++;
		alts2++;
		n--;
	}
	return (0);
}
