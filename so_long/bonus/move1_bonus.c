/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move1_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 09:46:13 by msamilog          #+#    #+#             */
/*   Updated: 2023/10/11 16:36:06 by msamilog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_right(t_data *data, int y, int x)
{
	data->map[y][x] = '0';
	data->map[y][x + 1] = 'P';
	data->player_x = x + 1;
	step_counter(data);
}

void	ft_left(t_data *data, int y, int x)
{
	data->map[y][x] = '0';
	data->map[y][x - 1] = 'P';
	data->player_x = x - 1;
	step_counter(data);
}

void	ft_up(t_data *data, int y, int x)
{
	data->map[y][x] = '0';
	data->map[y + 1][x] = 'P';
	data->player_y = y + 1;
	step_counter(data);
}

void	ft_down(t_data *data, int y, int x)
{
	data->map[y][x] = '0';
	data->map[y - 1][x] = 'P';
	data->player_y = y - 1;
	step_counter(data);
}

int	handle_key_press(int keycode, t_data *data)
{
	int	x;
	int	y;

	x = data->player_x;
	y = data->player_y;
	if (keycode == 53)
		ft_close_window(data);
	if (keycode == 2 && ft_coordinate(x + 1, y, data))
	{
		ft_right(data, y, x);
		data->p_right = 1;
	}
	else if (keycode == 0 && ft_coordinate(x - 1, y, data))
	{
		ft_left(data, y, x);
		data->p_right = 0;
	}
	else if (keycode == 1 && ft_coordinate(x, y + 1, data))
		ft_up(data, y, x);
	else if (keycode == 13 && ft_coordinate(x, y - 1, data))
		ft_down(data, y, x);
	image_to_screen(data);
	return (0);
}
