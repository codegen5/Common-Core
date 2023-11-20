/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operations1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:02:43 by msamilog          #+#    #+#             */
/*   Updated: 2023/11/20 20:17:12 by msamilog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *s)
{
	int	temp;

	if (s->a_size < 2)
		return ;
	temp = s->stack_a[0];
	s->stack_a[0] = s->stack_a[1];
	s->stack_a[1] = temp;
	write(1, "sa\n", 3);
}

void	sb(t_stack *s)
{
	int	temp;

	if (s->b_size < 2)
		return ;
	temp = s->stack_b[0];
	s->stack_b[0] = s->stack_b[1];
	s->stack_b[1] = temp;
	write(1, "sb\n", 3);
}

void	ss(t_stack *s)
{
	int	temp;

	if (s->a_size < 2 || s->b_size < 2)
		return ;
	temp = s->stack_a[0];
	s->stack_a[0] = s->stack_a[1];
	s->stack_a[1] = temp;
	temp = s->stack_b[0];
	s->stack_b[0] = s->stack_b[1];
	s->stack_b[1] = temp;
	write(1, "ss\n", 3);
}

void	pa(t_stack *s)
{
	int	i;

	i = 0;
	if (s->b_size)
	{
		if (!(s->a_size))
		{
			s->stack_a[0] = s->stack_b[0];
			s->a_size = 1;
		}
		else
		{
			while (i++ < s->a_size)
				s->stack_a[i] = s->stack_a[i - 1];
			s->stack_a[0] = s->stack_b[0];
			s->a_size++;
			i = s->b_size;
			while (i--)
				s->stack_b[i] = s->stack_b[i + 1];
			s->b_size--;
		}
		write(1, "pa\n", 3);
	}
}

void	pb(t_stack *s)
{
	int	i;

	i = 0;
	if (s->a_size)
	{
		if (!(s->b_size))
		{
			s->stack_b[0] = s->stack_a[0];
			s->b_size = 1;
		}
		else
		{
			while (i++ < s->b_size)
				s->stack_b[i] = s->stack_b[i - 1];
			s->stack_b[0] = s->stack_a[0];
			s->b_size++;
			i = s->a_size;
			while (i--)
				s->stack_a[i] = s->stack_a[i + 1];
			s->a_size--;
		}
		write(1, "pb\n", 3);
	}
}