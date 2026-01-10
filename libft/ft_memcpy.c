/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhlil <mlakhlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 20:42:32 by mlakhlil          #+#    #+#             */
/*   Updated: 2025/10/17 22:24:45 by mlakhlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*altdest;
	unsigned char	*altsrc;

	if (dst == NULL || src == NULL)
		return (NULL);
	altdest = (unsigned char *)dst;
	altsrc = (unsigned char *)src;
	while (n--)
		*altdest++ = *altsrc++;
	return (dst);
}
