/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:37:12 by msamilog          #+#    #+#             */
/*   Updated: 2023/12/08 16:21:47 by msamilog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_sort(t_stack *s)
{
	if (!is_sorted(s->stack_a, s->a_size))
	{
		ft_memcpy(s->index_a, s->stack_a, s->a_size * sizeof(int));
		bubble_sort_inv(s->index_a, s->a_size);
		if (s->a_size > 3)
		{
			push_minus_3(s);
			if (is_sorted(s->stack_a, s->a_size))
				rotate_b(s, max_num_stack_b(s));
			else
			{
				if (threesort_rot_moves(s) > 0 && max_num_stack_b > 0)
					rr(s);
				else if (threesort_rot_moves(s) < 0 && max_num_stack_b < 0)
					rrr(s);
				tiny_sort(s);
				rotate_b(s, max_num_stack_b(s));
			}
			final_push(s);
		}
		else
			tiny_sort(s);
	}
}

int	main(int ac, char **av)
{
	t_stack	*s;

	if (ac < 2)
		exit (1);
	s = malloc(sizeof(t_stack));
	if (!s)
		exit (1);
	s->a_size = 0;
	s->b_size = 0;
	check_error(ac, av, s);
	ft_sort(s);
	free_all(s);
	return (0);
}
