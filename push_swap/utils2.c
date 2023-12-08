/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:51:22 by msamilog          #+#    #+#             */
/*   Updated: 2023/12/08 11:21:37 by msamilog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	find_pos_low(t_stack *s, int num, int *p)
{
	int	i;
	int	pos_low;

	i = 0;
	pos_low = 2147483647;
	while (i < s->b_size)
	{
		if (num - s->stack_b[i] > 0)
		{
			if (num - s->stack_b[i] < pos_low)
			{
				pos_low = num - s->stack_b[i];
				*p = i;
			}
		}
		i++;
	}
	return (pos_low);
}

int	find_neg_low(t_stack *s, int num, int *n)
{
	int	i;
	int	neg_low;

	i = 0;
	neg_low = -2147483648;
	while (i < s->b_size)
	{
		if (num - s->stack_b[i] < 0)
		{
			if (num - s->stack_b[i] > neg_low)
			{
				neg_low = num - s->stack_b[i];
				*n = i;
			}
		}
		i++;
	}
	return (neg_low);
}

int	find_rot_b(t_stack *s, int num)
{
	int	p;
	int	n;
	int	pos_low;
	int	neg_low;

	pos_low = find_pos_low(s, num, &p);
	neg_low = find_neg_low(s, num, &n);
	if (ft_abs(neg_low) < pos_low)
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
