/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 23:43:01 by msamilog          #+#    #+#             */
/*   Updated: 2023/12/08 01:33:45 by msamilog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	convert_arg(int ac, char **av, t_stack *s)
{
	int		i;
	int		j;
	int		k;
	char	**numbers;

	i = 0;
	k = 0;
	while (++i < ac)
	{
		numbers = ft_split(av[i], ' ');
		j = 0;
		while (numbers[j])
			s->stack_a[k++] = ft_atoint(numbers[j++]);
		free_strings(numbers);
	}
}
