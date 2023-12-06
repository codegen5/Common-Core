/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:37:12 by msamilog          #+#    #+#             */
/*   Updated: 2023/12/06 22:32:04 by msamilog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	s->stack_a = NULL;
	s->stack_b = NULL;
	s->index_a = NULL;
	check_error(ac, av, s);
	if (!is_sorted(s->stack_a, s->a_size))
	{
		s->index_a = malloc(sizeof(int) * (s->a_size + 1));
		ft_memcpy(s->index_a, s->stack_a, s->a_size * sizeof(int));
		bubble_sort_inv(s->index_a, s->a_size);
		if (s->a_size > 3)
		{
			push_minus_3(s);
		}
	}
	return (0);
}
