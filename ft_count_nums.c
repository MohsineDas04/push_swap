/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_nums.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhlil <mlakhlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 19:20:31 by mlakhlil          #+#    #+#             */
/*   Updated: 2025/12/28 17:52:44 by mlakhlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_loop_insider(char **argv, int i, int j, int counter)
{
	if (argv[i][j] == '-' || argv[i][j] == '+')
		j++;
	while (argv[i][j])
	{
		if (argv[i][j] >= '0' && argv[i][j] <= '9')
		{
			counter++;
			while (argv[i][j] != ' ' && argv[i][j])
			{
				if (argv[i][j] >= '0' && argv[i][j] <= '9')
					j++;
				else
					return (write(2, "Error\n", 6), 0);
			}
		}
		else
			j++;
	}
	return (counter);
}

int	ft_loop_counter(int argc,
	char **argv, int counter)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		j = 0;
		if (ft_is_only_digit(argv[i]) == 0)
			return (write(2, "Error\n", 6), 0);
		else if (ft_much_arg(argv[i]) == 0)
			return (write(2, "Error\n", 6), 0);
		if (ft_much_arg(argv[i]) > 1)
		{
			counter = ft_loop_insider(argv, i, j, counter);
		}
		else
			counter++;
		i++;
	}
	return (counter);
}

//*	calculates the real amount of numbers we have 
int	count_nums(int argc, char **argv)
{
	return (ft_loop_counter(argc, argv, 0));
}
