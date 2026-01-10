/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhlil <mlakhlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 03:01:34 by mlakhlil          #+#    #+#             */
/*   Updated: 2025/11/16 21:32:02 by mlakhlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_newline(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*arr;
	char	*svstate;
	size_t	total_len;
	char	*svs1;

	if (!s1)
		return (ft_strdup(s2));
	total_len = ft_strlen(s1) + ft_strlen(s2);
	arr = malloc(total_len + 1);
	if (!arr)
		return (NULL);
	svstate = arr;
	svs1 = s1;
	while (*s1)
	{
		*arr++ = *s1++;
	}
	while (*s2)
	{
		*arr++ = *s2++;
	}
	*arr = '\0';
	free(svs1);
	return (svstate);
}

int	ft_strlen(const char *s)
{
	int	counter;

	counter = 0;
	while (*s)
	{
		counter++;
		s++;
	}
	return (counter);
}

char	*ft_strdup(const char *s1)
{
	char	*arr;
	size_t	len;
	char	*sv;

	len = ft_strlen(s1);
	arr = (char *)malloc(len + 1);
	if (!arr)
		return (NULL);
	sv = arr;
	while (*s1)
	{
		*arr = *s1;
		arr++;
		s1++;
	}
	*arr = '\0';
	return (sv);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[len] = '\0';
	return (str);
}
