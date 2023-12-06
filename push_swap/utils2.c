/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:51:22 by msamilog          #+#    #+#             */
/*   Updated: 2023/12/07 02:05:50 by msamilog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_num_stack_b(t_stack *s)
{
	int	i;

	i = 0;
	i = find_index_highest(s->stack_b, s->b_size);
	if (s->b_size - i < i)
		return (-i);
	else
		return (i);
}

int	find_rot_b(t_stack *s, int num)
{
	int	i;
	int	r;
	int	lowest;

	i = 0;
	r = 0;
	lowest = num - s->stack_b[i];
	if (lowest == 1)
		return (0);
	while (++i < s->b_size)
	{
		if (num - s->stack_b[i] < lowest)
		{
			lowest = num - s->stack_b[i];
			r = i;
		}
		if (lowest == 1)
			return (i);
	}
	if (s->b_size - r < r)
		return (-r);
	else
		return (r);
}
