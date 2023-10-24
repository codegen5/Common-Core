/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_foe_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 13:46:48 by msamilog          #+#    #+#             */
/*   Updated: 2023/10/24 13:58:09 by msamilog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_foe_right(t_data *data, int y, int x)
{
	data->map[y][x] = '0';
	data->map[y][x + 1] = 'F';
	data->foe_x = x + 1;
}

void	ft_foe_left(t_data *data, int y, int x)
{
	data->map[y][x] = '0';
	data->map[y][x - 1] = 'F';
	data->foe_x = x - 1;
}

void	ft_foe_up(t_data *data, int y, int x)
{
	data->map[y][x] = '0';
	data->map[y + 1][x] = 'F';
	data->foe_y = y + 1;
}

void	ft_foe_down(t_data *data, int y, int x)
{
	data->map[y][x] = '0';
	data->map[y - 1][x] = 'F';
	data->foe_y = y - 1;
}

int	foe_random_move(t_data *data)
{
	static int	timer = 0;
	int			direction;
	int			x;
	int			y;

	animate_exit(data);
	if (timer++ > 300)
	{
		x = data->foe_x;
		y = data->foe_y;
		direction = rand() % 4;
		if (direction == 0 && ft_foe_coordinate(x + 1, y, data))
			ft_foe_right(data, y, x);
		else if (direction == 1 && ft_foe_coordinate(x - 1, y, data))
			ft_foe_left(data, y, x);
		else if (direction == 2 && ft_foe_coordinate(x, y + 1, data))
			ft_foe_up(data, y, x);
		else if (direction == 3 && ft_foe_coordinate(x, y - 1, data))
			ft_foe_down(data, y, x);
		timer = 0;
		image_to_screen(data);
	}
	return (0);
}
