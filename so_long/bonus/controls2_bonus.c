/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 09:46:13 by msamilog          #+#    #+#             */
/*   Updated: 2023/10/24 14:00:15 by msamilog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	e_finder(t_data *data, int i, int j)
{
	data->exit_x = j;
	data->exit_y = i;
}

void	f_finder(t_data *data, int i, int j)
{
	data->foe_x = j;
	data->foe_y = i;
}

int	find_player(t_data *data, char find)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
			{
				data->player_x = j;
				data->player_y = i;
			}
			if (data->map[i][j] == 'E')
				e_finder(data, i, j);
			else if (data->map[i][j] == 'F')
				f_finder(data, i, j);
			else if (data->c_map[i][j] == find || data->c_map[i][j] == find)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	unvalid_map(t_data *data, int x, int y)
{
	if (data->c_map[y][x] == 'E')
	{
		data->exit_valid = 1;
		data->c_map[y][x] = '1';
	}
	if (data->c_map[y][x] == 'C')
	{
		data->collectible_count_copy++;
		data->c_map[y][x] = '0';
	}
	if (data->c_map[y][x] == '0' || data->c_map[y][x] == 'P')
	{
		data->c_map[y][x] = '.';
		unvalid_map(data, x, y + 1);
		unvalid_map(data, x, y - 1);
		unvalid_map(data, x + 1, y);
		unvalid_map(data, x - 1, y);
	}
	return ;
}

int	another_coin(t_data *data)
{
	find_player(data, 'P');
	unvalid_map(data, data->player_x, data->player_y);
	if (data->collectible_count_copy != data->collectible_count)
		ft_error("Can't access to coin!\n", data);
	if (!data->exit_valid)
		ft_error("Can't access to exit!\n", data);
	if (find_player(data, 'C') || find_player(data, 'E'))
		return (1);
	return (0);
}
