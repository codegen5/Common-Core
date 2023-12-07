/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:38:26 by msamilog          #+#    #+#             */
/*   Updated: 2023/12/07 04:57:21 by msamilog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicate(int ac, char **av, t_stack *s)
{
	int	i;
	int	j;

	s->stack_a = malloc(sizeof(int) * (s->a_size + 1));
	s->stack_b = malloc(sizeof(int) * (s->a_size + 1));
	if (!(s->stack_a) || !(s->stack_b))
		exit (1);
	convert_arg(ac, av, s);
	i = 0;
	while (i < s->a_size - 1)
	{
		j = i + 1;
		while (j < s->a_size)
		{
			if (s->stack_a[i] == s->stack_a[j++])
			{
				free(s->stack_a);
				return (1);
			}
		}
		i++;
	}
	return (0);
}

int	check_digit(char *number)
{
	int	i;

	i = 0;
	if (!number[i])
		return (0);
	if (number[i] == '+' || number[i] == '-')
		i++;
	if (!number[i])
		return (0);
	while (number[i])
	{
		if (!ft_isdigit(number[i++]))
			return (0);
	}
	return (1);
}

int	check_num(char **numbers)
{
	int	i;

	i = 0;
	if (!numbers[i])
		return (0);
	while (numbers[i])
	{
		if (!check_digit(numbers[i]) || ((check_digit(numbers[i]) && \
		!ft_atoint(numbers[i]) && ft_strncmp(numbers[i], "0", 1))))
			return (0);
		i++;
	}
	return (i);
}

void	check_error(int ac, char **av, t_stack *s)
{
	int		i;
	int		result;
	char	**numbers;

	i = 0;
	while (++i < ac)
	{
		numbers = ft_split(av[i], ' ');
		result = check_num(numbers);
		if (!result)
		{
			free_strings(numbers);
			ft_putstr_fd("Error\n", 2);
			exit (1);
		}
		s->a_size += result;
		free_strings(numbers);
	}
	if (check_duplicate(ac, av, s))
	{
		ft_putstr_fd("Error\n", 2);
		exit (1);
	}
}
