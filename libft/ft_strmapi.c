/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhlil <mlakhlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 02:31:22 by mlakhlil          #+#    #+#             */
/*   Updated: 2025/10/18 03:18:15 by mlakhlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	s_len;
	int		i;
	char	*arr;

	if (!s || !f)
		return (NULL);
	s_len = ft_strlen(s);
	i = 0;
	arr = malloc(s_len + 1);
	if (!arr)
		return (NULL);
	while (*s)
	{
		arr[i] = f(i, *s);
		i++;
		s++;
	}
	arr[i] = '\0';
	return (arr);
}
