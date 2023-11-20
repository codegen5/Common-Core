/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:37:12 by msamilog          #+#    #+#             */
/*   Updated: 2023/11/20 20:14:11 by msamilog         ###   ########.fr       */
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
	s->sorted = NULL;
	check_error(ac, av, s);
	sa(s);
	return (0);
}
