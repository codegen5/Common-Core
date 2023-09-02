/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 09:46:13 by msamilog          #+#    #+#             */
/*   Updated: 2023/09/02 14:17:12 by msamilog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	ft_coordinate(int x, int y, t_data *data)
{
	if (data->map[y][x] == 'C')
	{
		data->player_collected++;
	}
	else if (data->map[y][x] == 'E')
	{
		if (data->player_collected == data->collectible_count)
		{
			step_counter(data);
			ft_close_window(data);
		}
		return (0);
	}
	else if (data->map[y][x] == 'F')
	{
		step_counter(data);
		ft_close_window(data);
	}
	else if (data->map[y][x] == '1')
		return (0);
	return (1);
}

void	step_counter(t_data *data)
{
	char	*str;

	free(data->player_step_screen);
	str = ft_itoa(data->player_step);
	data->player_step_screen = ft_strjoin("STEP: ", str);
	free(str);
	data->player_step++;
}
