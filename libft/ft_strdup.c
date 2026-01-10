/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhlil <mlakhlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:20:17 by mlakhlil          #+#    #+#             */
/*   Updated: 2025/10/21 18:26:24 by mlakhlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*arr;
	size_t	len;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	arr = (char *)malloc(len + 1);
	if (!arr)
		return (NULL);
	ft_memcpy(arr, s1, len + 1);
	return (arr);
}
