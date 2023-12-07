/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 22:32:33 by msamilog          #+#    #+#             */
/*   Updated: 2023/12/07 05:03:46 by msamilog         ###   ########.fr       */
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
	while (s->a_size > 3)
	{
		if (s->stack_a[0] < s->index_a[2])
		{
			if (is_b_min_max(s, s->stack_a[0]))
				rotate_b(s, max_num_stack_b(s));
			else
				rotate_b(s, find_rot_b(s, s->stack_a[0]));
			pb(s);
		}
		else
		{
			if ((is_b_min_max(s, s->stack_a[1]) && max_num_stack_b(s) > 0)
				|| (!is_b_min_max(s, s->stack_a[1])
					&& find_rot_b(s, s->stack_a[1]) > 0))
				rr(s);
			else
				ra(s);
		}
	}
}
