/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:13:33 by msamilog          #+#    #+#             */
/*   Updated: 2023/12/08 09:09:48 by msamilog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_strings(char **strings)
{
	int	count;

	count = 0;
	while (strings[count])
		free(strings[count++]);
	free(strings);
}

void	free_all(t_stack *s)
{
	free(s->stack_a);
	free(s->stack_b);
	free(s->index_a);
}
