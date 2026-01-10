/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhlil <mlakhlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 13:37:57 by mlakhlil          #+#    #+#             */
/*   Updated: 2025/10/18 15:03:57 by mlakhlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;

	srclen = ft_strlen(src);
	if (dstsize > 0)
	{
		while (*src && dstsize - 1 > 0)
		{
			*dst = *src;
			src++;
			dst++;
			dstsize--;
		}
		*dst = '\0';
	}
	return (srclen);
}
