/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhlil <mlakhlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 16:51:09 by mlakhlil          #+#    #+#             */
/*   Updated: 2025/12/24 20:54:40 by mlakhlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

void	ft_check_exe(int *arr, int allsize);
char	*get_next_line(int fd);
void	ft_ins_exe(char *ins, t_data **a_stack, t_data **b_stack);

#endif
