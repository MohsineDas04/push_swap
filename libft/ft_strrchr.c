/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhlil <mlakhlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:54:05 by mlakhlil          #+#    #+#             */
/*   Updated: 2025/10/14 09:54:33 by mlakhlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	length;

	length = ft_strlen(s);
	s += length;
	while (length > 0)
	{
		if (*s == c)
			return ((char *)s);
		s--;
		length--;
	}
	if (*s == c)
		return ((char *)s);
	return (NULL);
}
