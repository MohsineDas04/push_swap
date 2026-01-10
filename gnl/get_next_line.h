/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhlil <mlakhlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 17:57:47 by mlakhlil          #+#    #+#             */
/*   Updated: 2025/11/18 18:52:53 by mlakhlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <ctype.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10

# endif

char	*get_next_line(int fd);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
int		ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, int n);
int		check_newline(const char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*cp_line(char *str);
char	*free_line(char *str, int count);

#endif
