/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 22:32:33 by msamilog          #+#    #+#             */
/*   Updated: 2023/12/03 00:51:20 by msamilog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_next(t_stack *s, int j)
{
	int	i;

	i = 0;
	while (i < s->a_size)
	{
		if (s->index[j] == s->stack_a[i])
		{
			if (s->a_size - i > i)
				return (i);
			else
				return (-(s->a_size - i));
		}
		i++;
	}
	return (0);
}

void	push_pull(t_stack *s)
{
	int	i;
	int	j;

	j = 0;
	while (s->a_size > 1)
	{
		i = find_next(s, j++);
		while (i > 0)
		{
			ra(s);
			i--;
		}
		while (i < 0)
		{
			rra(s);
			i++;
		}
		pb(s);
	}
	while (s->b_size)
		pa(s);
}
