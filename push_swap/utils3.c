/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:19:15 by msamilog          #+#    #+#             */
/*   Updated: 2023/12/08 10:55:24 by msamilog         ###   ########.fr       */
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

int	get_move_count(t_stack *s, int i)
{
	int	move_count;

	move_count = 0;
	if (s->a_size - i > i)
		move_count += i;
	else
		move_count += s->a_size - i;
	if (is_b_min_max(s, s->stack_a[i]))
		move_count += ft_abs(max_num_stack_b(s));
	else
		move_count += ft_abs(find_rot_b(s, s->stack_a[i]));
	return (move_count);
}

int	get_shortest_index(t_stack *s)
{
	int	shortest;
	int	i;
	int	n;
	int	move_count;

	shortest = 2147483647;
	i = 0;
	while (i < s->a_size)
	{
		if (s->stack_a[i] < s->index_a[2])
		{
			move_count = get_move_count(s, i);
			if (move_count < shortest)
			{
				n = i;
				shortest = move_count;
			}
		}
		i++;
	}
	return (n);
}
