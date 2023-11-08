/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:38:26 by msamilog          #+#    #+#             */
/*   Updated: 2023/10/30 23:52:20 by msamilog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicate(int ac, char **av, t_list *lst)
{
	stack_init(ac, av, lst);
}

size_t	count_strings(char **array)
{
	size_t	count;

	count = 0;
	while (array[count])
	{
		count++;
	}
	return (count);
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
		if (!check_digit(numbers[i++]))
			return (0);
	}
	return (1);
}

void	check_error(int ac, char **av, t_list *lst)
{
	int		i;
	char	**numbers;

	if (ac < 2)
	{
		ft_putstr_fd("Error!\n", 2);
		exit (1);
	}
	i = 0;
	while (++i < ac)
	{
		numbers = ft_split(av[i], ' ');
		if (!check_num(numbers))
		{
			ft_deallocate(numbers, count_strings(numbers));
			ft_putstr_fd("Error!\n", 2);
			exit (1);
		}
		ft_deallocate(numbers, count_strings(numbers));
	}
	if (!check_duplicate(ac, av, lst))
	{
		ft_putstr_fd("Error!\n", 2);
		exit (1);
	}
}
