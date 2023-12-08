/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 22:32:33 by msamilog          #+#    #+#             */
/*   Updated: 2023/12/08 16:27:57 by msamilog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_push(t_stack *s)
{
	while (s->b_size)
		pa(s);
}

void	rotate_a(t_stack *s, int r)
{
	while (r > 0)
	{
		ra(s);
		r--;
	}
	while (r < 0)
	{
		rra(s);
		r++;
	}
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

void	rotate_both(t_stack *s, int *r_a, int *r_b, int direction)
{
	if (direction == 1)
	{
		while (*r_a > 0 && *r_b > 0)
		{
			rr(s);
			*r_a -= 1;
			*r_b -= 1;
		}
	}
	else
	{
		while (*r_a < 0 && *r_b < 0)
		{
			rrr(s);
			*r_a += 1;
			*r_b += 1;
		}
	}
}

void	push_minus_3(t_stack *s)
{
	int	i;
	int	r_a;
	int	r_b;

	while (s->a_size > 3)
	{
		r_a = 0;
		r_b = 0;
		i = get_shortest_index(s);
		if (s->a_size - i > i)
			r_a = i;
		else
			r_a = i - s->a_size;
		if (is_b_min_max(s, s->stack_a[i]))
			r_b = max_num_stack_b(s);
		else
			r_b = find_rot_b(s, s->stack_a[i]);
		if ((r_a > 0 && r_b > 0) || (r_a < 0 && r_b < 0))
			rotate_both(s, &r_a, &r_b, (r_a > 0 && r_b > 0));
		rotate_a(s, r_a);
		rotate_b(s, r_b);
		pb(s);
	}
}
