/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:38:26 by msamilog          #+#    #+#             */
/*   Updated: 2023/10/25 18:18:03 by msamilog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_error(int ac, char **av)
{
	if (ac < 2)
	{
		(void)av;
		ft_putstr_fd("Error\nInvalid arg count!\n", 2);
		exit (1);
	}
}