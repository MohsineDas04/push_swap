/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhlil <mlakhlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 19:20:05 by mlakhlil          #+#    #+#             */
/*   Updated: 2025/12/24 18:22:33 by mlakhlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_loop(int j, int argc, char **argv,
	int *arr)
{
	char	**nums;
	int		i;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (ft_much_arg(argv[i]) > 1)
		{
			nums = ft_split(argv[i], ' ');
			while (nums[j])
			{
				*arr = ft_atoi(nums[j]);
				j++;
				arr++;
			}
			free_nums(nums);
		}
		else
		{
			*arr = ft_atoi(argv[i]);
			arr++;
		}
		i++;
	}
}

int	*ft_put_args(int argc, char **argv, int *arr)
{
	int	j;

	j = 0;
	ft_loop(j, argc, argv, arr);
	return (arr);
}
