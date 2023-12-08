/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operations3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:57:08 by msamilog          #+#    #+#             */
/*   Updated: 2023/12/08 15:40:58 by msamilog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *s)
{
	int	i;

	i = s->a_size - 1;
	if (s->a_size > 1)
	{
		s->stack_a[s->a_size] = s->stack_a[s->a_size - 1];
		while (i > 0)
		{
			s->stack_a[i] = s->stack_a[i - 1];
			i--;
		}
		s->stack_a[0] = s->stack_a[s->a_size];
	}
	write(1, "rra\n", 4);
}

void	rrb(t_stack *s)
{
	int	i;

	i = s->b_size - 1;
	if (s->b_size > 1)
	{
		s->stack_b[s->b_size] = s->stack_b[s->b_size - 1];
		while (i > 0)
		{
			s->stack_b[i] = s->stack_b[i - 1];
			i--;
		}
		s->stack_b[0] = s->stack_b[s->b_size];
	}
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *s)
{
	int	i;

	i = s->a_size - 1;
	if (s->a_size > 1)
	{
		s->stack_a[s->a_size] = s->stack_a[s->a_size - 1];
		while (i > 0)
		{
			s->stack_a[i] = s->stack_a[i - 1];
			i--;
		}
		s->stack_a[0] = s->stack_a[s->a_size];
	}
	i = s->b_size - 1;
	if (s->b_size > 1)
	{
		s->stack_b[s->b_size] = s->stack_b[s->b_size - 1];
		while (i > 0)
		{
			s->stack_b[i] = s->stack_b[i - 1];
			i--;
		}
		s->stack_b[0] = s->stack_b[s->b_size];
	}
	write(1, "rrr\n", 4);
}
