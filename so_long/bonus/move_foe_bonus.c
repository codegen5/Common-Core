/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_foe_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 13:46:48 by msamilog          #+#    #+#             */
/*   Updated: 2023/09/08 19:58:44 by msamilog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_foe_right(t_data *data, int y, int x)
{
	data->map[y][x] = '0';
	data->map[y][x + 1] = 'F';
	data->foe_x = x + 1;
	step_counter(data);
}

void	ft_foe_left(t_data *data, int y, int x)
{
	data->map[y][x] = '0';
	data->map[y][x - 1] = 'F';
	data->foe_x = x - 1;
	step_counter(data);
}

void	ft_foe_up(t_data *data, int y, int x)
{
	data->map[y][x] = '0';
	data->map[y + 1][x] = 'F';
	data->foe_y = y + 1;
	step_counter(data);
}

void	ft_foe_down(t_data *data, int y, int x)
{
	data->map[y][x] = '0';
	data->map[y - 1][x] = 'F';
	data->foe_y = y - 1;
	step_counter(data);
}

void	foe_random_move(t_data *data)
{
	int	num;
	int	x;
	int	y;

	x = data->foe_x;
	y = data->foe_y;
	num = rand() % 4;
	if (num == 0)
		ft_foe_right(data, y, x);
	else if (num == 1)
		ft_foe_left(data, y, x);
	else if (num == 2)
		ft_foe_up(data, y, x);
	else if (num == 3)
		ft_foe_down(data, y, x);
	image_to_screen(data);
}
