/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhlil <mlakhlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:21:08 by mlakhlil          #+#    #+#             */
/*   Updated: 2025/10/16 17:31:14 by mlakhlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_it(char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s1len;
	size_t	counter;

	if (!s1 || !set)
		return (NULL);
	s1len = ft_strlen(s1);
	counter = 0;
	while (s1[counter] && is_in_it(s1[counter], set) == 1)
	{
		counter++;
	}
	while (s1len > counter && is_in_it(s1[s1len - 1], set) == 1)
		s1len--;
	return (ft_substr(&s1[0], counter, s1len - counter));
}
