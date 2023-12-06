/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 22:32:33 by msamilog          #+#    #+#             */
/*   Updated: 2023/12/07 02:06:14 by msamilog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_b(t_stack *s, int r)
{
	while (r-- > 0)
		rb(s);
	while (r-- < 0)
		rrb(s);
}

void	push_minus_3(t_stack *s)
{
	int	i;

	i = 0;
	while (s->a_size > 3)
	{
		if (s->stack_a[++i] < s->index_a[2])
		{
			if (is_b_min_max(s, s->stack_a[i]))
				rotate_b(s, max_num_stack_b(s));
			else
				rotate_b(s, find_rot_b(s, s->stack_a[i]));
			pb(s);
		}
		else
		{
			if ((is_b_min_max(s, s->stack_a[i + 1]) && max_num_stack_b(s) > 0)
				|| (!is_b_min_max(s, s->stack_a[i + 1])
					&& find_rot_b(s, s->stack_a[i + 1]) > 0))
				rr(s);
			else
				ra(s);
		}
		i++;
	}
}
