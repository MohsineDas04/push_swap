/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhlil <mlakhlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 15:05:33 by mlakhlil          #+#    #+#             */
/*   Updated: 2025/10/18 20:39:40 by mlakhlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstsize == 0)
		return (srclen);
	dst += dstlen;
	if (dstlen >= dstsize)
		return (srclen + dstsize);
	if (dstsize > dstlen)
	{
		while (*src && (dstsize - 1) - dstlen > 0)
		{
			*dst = *src;
			dst++;
			src++;
			dstsize--;
		}
	}
	*dst = '\0';
	return (dstlen + srclen);
}
