/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 09:46:13 by msamilog          #+#    #+#             */
/*   Updated: 2023/10/22 16:09:07 by msamilog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_exit(char *msg)
{
	write(1, "Error\n", 6);
	ft_putstr(msg);
	exit(1);
}

void	ft_error(char *msg, t_data *data)
{
	int	i;

	i = 0;
	write(1, "Error\n", 6);
	ft_putstr(msg);
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map[i]);
	exit(1);
}

int	ft_close_window(t_data *data, int stat)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map[i]);
	if (stat == -1)
		ft_putstr("Game closed\n");
	else if (stat == 1)
		ft_putstr("You win!\n");
	else
		ft_putstr("You lost!\n");
	exit(0);
}
