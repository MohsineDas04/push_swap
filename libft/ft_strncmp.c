/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhlil <mlakhlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 07:24:40 by mlakhlil          #+#    #+#             */
/*   Updated: 2025/10/22 10:47:37 by mlakhlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*alts1;
	unsigned char	*alts2;
	size_t			i;

	if (n == 0)
		return (0);
	i = 1;
	alts1 = (unsigned char *)s1;
	alts2 = (unsigned char *)s2;
	while (*alts1 && (*alts1 == *alts2) && *alts2 && i < n)
	{
		alts1++;
		alts2++;
		i++;
	}
	return (*alts1 - *alts2);
}
