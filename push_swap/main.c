/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:37:12 by msamilog          #+#    #+#             */
/*   Updated: 2023/12/03 00:52:36 by msamilog         ###   ########.fr       */
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
	s->index = NULL;
	check_error(ac, av, s);
	if (!is_sorted(s->stack_a, s->a_size))
	{
		s->index = malloc(sizeof(int) * (s->a_size + 1));
		ft_memcpy(s->index, s->stack_a, s->a_size * sizeof(int));
		bubble_sort(s->index, s->a_size);
		push_pull(s);
	}
	return (0);
}
