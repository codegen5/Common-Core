/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operations2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:02:46 by msamilog          #+#    #+#             */
/*   Updated: 2023/11/22 15:42:51 by msamilog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *s)
{
	int	i;

	i = 0;
	if (s->a_size > 1)
	{
		s->stack_a[s->a_size] = s->stack_a[0];
		while (i < s->a_size)
		{
			s->stack_a[i] = s->stack_a[i + 1];
			i++;
		}
	}
	write(1, "ra\n", 3);
}

void	rb(t_stack *s)
{
	int	i;

	i = 0;
	if (s->b_size > 1)
	{
		s->stack_b[s->b_size] = s->stack_b[0];
		while (i < s->b_size)
		{
			s->stack_b[i] = s->stack_b[i + 1];
			i++;
		}
	}
	write(1, "rb\n", 3);
}

void	rr(t_stack *s)
{
	int	i;

	i = 0;
	if (s->a_size > 1)
	{
		s->stack_a[s->a_size] = s->stack_a[0];
		while (i < s->a_size)
		{
			s->stack_a[i] = s->stack_a[i + 1];
			i++;
		}
	}
	i = 0;
	if (s->b_size > 1)
	{
		s->stack_b[s->b_size] = s->stack_b[0];
		while (i < s->b_size)
		{
			s->stack_b[i] = s->stack_b[i + 1];
			i++;
		}
	}
	write(1, "rr\n", 3);
}
