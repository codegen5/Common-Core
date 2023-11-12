/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:38:26 by msamilog          #+#    #+#             */
/*   Updated: 2023/11/12 20:19:30 by msamilog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicate(int ac, char **av, int count)
{
	int	*num_array;
	int	i;
	int	j;

	num_array = malloc(sizeof(int) * count);
	if (!num_array)
		exit (1);
	convert_arg(ac, av, num_array);
	i = 0;
	while (i < count - 1)
	{
		j = i + 1;
		while (j < count)
		{
			if (num_array[i] == num_array[j++])
			{
				free(num_array);
				return (0);
			}
		}
		i++;
	}
	free(num_array);
	return (1);
}

int	check_digit(char *number)
{
	size_t	i;

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
	size_t	i;

	i = 0;
	if (!numbers[i])
		return (0);
	while (numbers[i])
	{
		if (!check_digit(numbers[i]) || (check_digit(numbers[i])
				&& !ft_atoint(numbers[i])))
			return (0);
		i++;
	}
	return (i);
}

void	check_error(int ac, char **av)
{
	int		i;
	int		count;
	int		result;
	char	**numbers;

	i = 0;
	count = 0;
	while (++i < ac)
	{
		numbers = ft_split(av[i], ' ');
		result = check_num(numbers);
		if (!result)
		{
			free_strings(numbers);
			ft_putstr_fd("Error!\n", 2);
			exit (1);
		}
		count += result;
		free_strings(numbers);
	}
	if (!check_duplicate(ac, av, count))
	{
		ft_putstr_fd("Error!\n", 2);
		exit (1);
	}
}
