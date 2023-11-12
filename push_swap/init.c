/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 23:43:01 by msamilog          #+#    #+#             */
/*   Updated: 2023/11/12 18:59:37 by msamilog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	convert_arg(int ac, char **av, int *num_array)
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
		{
			num_array[k++] = ft_atoi(numbers[j++]);
		}
		free_strings(numbers);
	}
}
