/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:51:22 by msamilog          #+#    #+#             */
/*   Updated: 2023/12/08 01:18:30 by msamilog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

int	threesort_rot_moves(t_stack *s)
{
	int	i;

	i = find_index_highest(s->stack_a, 3);
	if (i == 0)
		return (1);
	else if (i == 1)
		return (-1);
	return (0);
}

int	max_num_stack_b(t_stack *s)
{
	int	i;

	i = 0;
	i = find_index_highest(s->stack_b, s->b_size);
	if (s->b_size - i < i)
		return (-(s->b_size - i));
	else
		return (i);
}

int	find_rot_b(t_stack *s, int num)
{
	int	i;
	int	p;
	int	n;
	int	pos_lowest;
	int	neg_lowest;

	i = 0;
	pos_lowest = 2147483647;
	neg_lowest = -2147483648;
	while (i < s->b_size)
	{
		if (num - s->stack_b[i] > 0)
		{
			if (num - s->stack_b[i] < pos_lowest)
			{
				pos_lowest = num - s->stack_b[i];
				p = i;
			}
		}
		else
		{
			if (num - s->stack_b[i] > neg_lowest)
			{
				neg_lowest = num - s->stack_b[i];
				n = i;
			}
		}
		i++;
	}
	if (ft_abs(neg_lowest) < pos_lowest)
	{
		if (s->b_size - n < n)
			return (-(s->b_size - n - 1));
		else
			return (n + 1);
	}
	else
	{
		if (s->b_size - p < p)
			return (-(s->b_size - p));
		else
			return (p);
	}
}
