/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhlil <mlakhlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:00:49 by mlakhlil          #+#    #+#             */
/*   Updated: 2025/11/18 18:44:42 by mlakhlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>

char	*read_fail_handle(char *temp_read, char **str)
{
	free(temp_read);
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*cp_line(char *str)
{
	char	*arr;
	int		count;
	char	*sv;

	count = 0;
	if (!str)
		return (NULL);
	while (str[count])
	{
		if (str[count] == '\n')
		{
			count++;
			break ;
		}
		count++;
	}
	arr = malloc(count + 1);
	if (!arr)
		return (NULL);
	sv = arr;
	while (count-- > 0)
		*arr++ = *str++;
	*arr = '\0';
	return (sv);
}

char	*free_line(char *str, int count)
{
	char	*arr;

	if (!str)
		return (NULL);
	arr = ft_substr(str, count, ft_strlen(str) - count);
	free(str);
	return (arr);
}

char	*free_str(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*str = NULL;
	char		*temp_read;
	char		*returnarr;
	int			read_res;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	read_res = 1;
	temp_read = malloc(BUFFER_SIZE + 1);
	if (!temp_read)
		return (NULL);
	while (check_newline(str) == 0 && read_res != 0)
	{
		read_res = read(fd, temp_read, BUFFER_SIZE);
		if (read_res == -1)
			return (read_fail_handle(temp_read, &str));
		temp_read[read_res] = '\0';
		str = ft_strjoin(str, temp_read);
	}
	free(temp_read);
	if (!str || !*str)
		return (free_str(&str));
	returnarr = cp_line(str);
	str = free_line(str, ft_strlen(returnarr));
	return (returnarr);
}
