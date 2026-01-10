/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhlil <mlakhlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:23:47 by mlakhlil          #+#    #+#             */
/*   Updated: 2025/10/21 21:02:53 by mlakhlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*arr;
	char	*svstate;
	size_t	total_len;

	if (!s1 || !s2)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	arr = malloc(total_len + 1);
	if (!arr)
		return (NULL);
	svstate = arr;
	while (*s1)
		*arr++ = *s1++;
	while (*s2)
	{
		*arr++ = *s2++;
	}
	*arr = '\0';
	return (svstate);
}
