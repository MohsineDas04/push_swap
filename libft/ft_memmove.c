/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhlil <mlakhlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 09:59:14 by mlakhlil          #+#    #+#             */
/*   Updated: 2025/10/21 15:10:27 by mlakhlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*altdst;
	unsigned char	*altsrc;

	if (!dst || !src)
		return (NULL);
	altdst = (unsigned char *)dst;
	altsrc = (unsigned char *)src;
	if (len == 0)
		return (dst);
	if (altdst > altsrc)
	{
		altdst += len - 1;
		altsrc += len - 1;
		while (len > 0)
		{
			*altdst-- = *altsrc--;
			len --;
		}
	}
	else
		ft_memcpy(altdst, altsrc, len);
	return (dst);
}
