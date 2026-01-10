/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhlil <mlakhlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:42:06 by mlakhlil          #+#    #+#             */
/*   Updated: 2025/10/15 11:03:26 by mlakhlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*arr;

	if (size != 0 && count > ((size_t)-1) / size)
		return (NULL);
	arr = (char *)malloc(count * size);
	if (!arr)
		return (NULL);
	ft_bzero(arr, count * size);
	return ((void *)arr);
}
