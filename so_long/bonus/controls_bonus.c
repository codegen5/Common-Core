/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 09:46:13 by msamilog          #+#    #+#             */
/*   Updated: 2023/10/24 14:19:37 by msamilog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	is_rectangular(t_data *data)
{
	int	i;
	int	line1_len;
	int	length;

	length = 0;
	i = 1;
	line1_len = ft_strlen(data->map[0]);
	data->map_x = line1_len;
	while (data->map[i])
	{
		length = ft_strlen(data->map[i]);
		if (length != line1_len)
			ft_error("Map is not rectangular!\n", data);
		i++;
	}
	if (i != data->map_y_control)
		ft_error("Map is not rectangular!\n", data);
	data->map_y = i;
}

void	invalid_mapname(char *mapname, t_data *data)
{
	int	length;

	length = ft_strlen(mapname);
	if (mapname[length - 1] != 'r' || mapname[length - 2] != 'e' \
			|| mapname[length - 3] != 'b' || mapname[length - 4] \
			!= '.' || length <= 5)
		ft_error("Invalid mapname!\n", data);
	while (mapname[length] != '/')
		length--;
	if (mapname[length + 1] == '.')
		ft_error("Invalid mapname!\n", data);
}

void	element_check(t_data *data)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			c = data->map[i][j];
			element_check2(data, c);
			j++;
		}
		i++;
	}
	if ((data->collectible_count < 1) || (data->p_count != 1)
		|| (data->e_count != 1) || (data->f_count != 1))
		ft_error("There must be 1P, 1E, 1F and at least 1C\n", data);
}

void	element_check2(t_data *data, char c)
{
	if (c == 'C')
		data->collectible_count++;
	if (c == 'P')
		data->p_count++;
	if (c == 'E')
		data->e_count++;
	if (c == 'F')
		data->f_count++;
	if (!(c == 'C' || c == 'P' || c == '0' || c == '1' || c == 'E' || c == 'F'))
		ft_error("Invalid char!\n", data);
}

void	wall_ok(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < data->map_x)
	{
		if (data->map[0][x] != '1' || data->map[data->map_y - 1][x] != '1')
			ft_error("Map is not surrounded by walls!\n", data);
		x++;
	}
	while (y < data->map_y)
	{
		if (data->map[y][0] != '1' || data->map[y][data->map_x - 1] != '1')
			ft_error("Map is not surrounded by walls!\n", data);
		y++;
	}
}
