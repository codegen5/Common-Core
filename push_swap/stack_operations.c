/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 22:32:33 by msamilog          #+#    #+#             */
/*   Updated: 2023/12/08 00:41:15 by msamilog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_push(t_stack *s)
{
	while (s->b_size)
		pa(s);
}

void	tiny_sort(t_stack *s)
{
	int	i;

	i = find_index_highest(s->stack_a, s->a_size);
	if (i == 0)
		ra(s);
	else if (i == 1)
		rra(s);
	if (s->stack_a[0] > s->stack_a[1])
		sa(s);
}

void	rotate_b(t_stack *s, int r)
{
	while (r > 0)
	{
		rb(s);
		r--;
	}
	while (r < 0)
	{
		rrb(s);
		r++;
	}
}

void	push_minus_3(t_stack *s)
{
	int	i;
	int	n;
	int	move_count;
	int	shortest;

	while (s->a_size > 3)
	{
		shortest = 2147483647;
		i = 0;
		while (i < s->a_size)
		{
			move_count = 0;
			if (s->stack_a[i] < s->index_a[2])
			{
				if (s->a_size - i > i)
					move_count += i;
				else
					move_count += s->a_size - i;
				if (is_b_min_max(s, s->stack_a[i]))
					move_count += ft_abs(max_num_stack_b(s));
				else
					move_count += ft_abs(find_rot_b(s, s->stack_a[i]));
				if (move_count < shortest)
				{
					n = i;
					shortest = move_count;
				}
			}
			i++;
		}
		if (s->a_size - n > n)
		{
			while (n--)
				ra(s);
		}
		else
		{
			while (s->a_size - n++)
				rra(s);
		}
		if (is_b_min_max(s, s->stack_a[0]))
			rotate_b(s, max_num_stack_b(s));
		else
			rotate_b(s, find_rot_b(s, s->stack_a[0]));
		pb(s);
	}
}
