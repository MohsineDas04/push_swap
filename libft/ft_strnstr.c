/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhlil <mlakhlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:55:53 by mlakhlil          #+#    #+#             */
/*   Updated: 2025/10/21 20:44:01 by mlakhlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		result;
	size_t	i;
	char	*statesv;
	size_t	needle_len;

	needle_len = ft_strlen(needle);
	i = 0;
	if (!*needle)
		return ((char *)haystack);
	while (i + needle_len <= len)
	{
		if (haystack[i] == *needle)
		{
			statesv = (char *)haystack + i;
			result = ft_strncmp((char *)haystack + i, (char *)needle,
					needle_len);
			if (result == 0)
				return (statesv);
		}
		i++;
	}
	return (NULL);
}
