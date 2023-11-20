/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operations3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:57:08 by msamilog          #+#    #+#             */
/*   Updated: 2023/11/20 20:12:18 by msamilog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *s)
{
	size_t	i;

	i = 0;
	if (s->a_size > 1)
	{
		s->stack_a[s->a_size] = s->stack_a[s->a_size - 1];
		while (i + 1 < s->a_size)
			s->stack_a[i + 1] = s->stack_a[i++];
		s->stack_a[0] = s->stack_a[s->a_size];
	}
	write(1, "rra\n", 3);
}

void	rrb(t_stack *s)
{
	size_t	i;

	i = 0;
	if (s->b_size > 1)
	{
		s->stack_b[s->b_size] = s->stack_b[s->b_size - 1];
		while (i + 1 < s->b_size)
			s->stack_b[i + 1] = s->stack_b[i++];
		s->stack_b[0] = s->stack_b[s->b_size];
	}
	write(1, "rrb\n", 3);
}

void	rrr(t_stack *s)
{
	size_t	i;

	i = 0;
	if (s->a_size > 1)
	{
		s->stack_a[s->a_size] = s->stack_a[s->a_size - 1];
		while (i + 1 < s->a_size)
			s->stack_a[i + 1] = s->stack_a[i++];
		s->stack_a[0] = s->stack_a[s->a_size];
	}
	i = 0;
	if (s->b_size > 1)
	{
		s->stack_b[s->b_size] = s->stack_b[s->b_size - 1];
		while (i + 1 < s->b_size)
			s->stack_b[i + 1] = s->stack_b[i++];
		s->stack_b[0] = s->stack_b[s->b_size];
	}
	write(1, "rrr\n", 3);
}
