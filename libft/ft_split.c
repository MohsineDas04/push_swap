/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhlil <mlakhlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:33:01 by mlakhlil          #+#    #+#             */
/*   Updated: 2025/10/21 21:18:14 by mlakhlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(char const *s, char c)
{
	size_t	in_word;
	size_t	count;

	in_word = 0;
	count = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			count++;
			in_word = 1;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	**free_all(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i++]);
	}
	free(arr);
	return (NULL);
}

static char	**heavy_work(const char *s, char c, char **arr, size_t c_counter)
{
	size_t	i;
	size_t	word_len;

	i = 0;
	while (*s && i < c_counter)
	{
		while (*s && *s == c)
		{
			s++;
		}
		word_len = 0;
		while (s[word_len] && s[word_len] != c)
		{
			word_len++;
		}
		arr[i] = ft_substr(s, 0, word_len);
		if (!arr[i])
			return (free_all(arr));
		i++;
		s += word_len;
	}
	arr[i] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	c_counter;

	if (!s)
		return (NULL);
	c_counter = word_count(s, c);
	arr = malloc(sizeof(char *) * (c_counter + 1));
	if (!arr)
		return (NULL);
	return (heavy_work(s, c, arr, c_counter));
}
