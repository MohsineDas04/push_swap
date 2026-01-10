/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhlil <mlakhlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:09:42 by mlakhlil          #+#    #+#             */
/*   Updated: 2025/11/05 14:16:51 by mlakhlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_printc(va_list my_args);
int		ft_printpercentage(char c);
int		ft_prints(va_list my_args);
int		ft_printdec(va_list my_args);
int		ft_printu(va_list my_args);
int		ft_printp(va_list my_args);
int		ft_print_hex(va_list my_args, char type);

void	ft_putnbr(int n);
void	ft_putnbr_u(unsigned int nb);
void	ft_putnbr_base(unsigned long long nb, const char *base);

#endif