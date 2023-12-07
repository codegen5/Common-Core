/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 19:30:48 by msamilog          #+#    #+#             */
/*   Updated: 2023/12/08 01:04:02 by msamilog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort_inv(int *arr, size_t size)
{
	size_t	i;
	size_t	j;
	int		temp;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j + i + 1 < size)
		{
			if (arr[j] < arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

int	is_b_min_max(t_stack *s, int num)
{
	int	lowest;
	int	highest;
	int	i;

	if (s->b_size > 1)
	{
		lowest = s->stack_b[0];
		highest = s->stack_b[0];
		i = 0;
		while (++i < s->b_size)
		{
			if (s->stack_b[i] > highest)
				highest = s->stack_b[i];
			else if (s->stack_b[i] < lowest)
				lowest = s->stack_b[i];
		}
		return (num < lowest || num > highest);
	}
	return (1);
}

int	find_index_highest(int *arr, int size)
{
	int	max;
	int	i;
	int	y;

	i = 0;
	y = 0;
	max = arr[i];
	while (i < size)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			y = i;
		}
		i++;
	}
	return (y);
}

int	is_sorted(int *arr, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size - 1)
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoint(char *str)
{
	int		i;
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result = result + str[i] - '0';
		if ((result > 2147483647 && sign == 1)
			|| (result > 2147483648 && sign == -1))
			return (0);
		i++;
	}
	return (result * sign);
}
