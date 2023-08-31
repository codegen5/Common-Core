/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 09:46:13 by msamilog          #+#    #+#             */
/*   Updated: 2023/08/31 16:49:51 by msamilog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	image_initialize(t_data *data)
{
	int	img_w;
	int	img_h;

	data->player_r = mlx_xpm_file_to_image(data->mlx, PL_R_XPM, &img_w, &img_h);
	data->player_l = mlx_xpm_file_to_image(data->mlx, PL_L_XPM, &img_w, &img_h);
	data->exit = mlx_xpm_file_to_image(data->mlx, EX_XPM, &img_w, &img_h);
	data->wall = mlx_xpm_file_to_image(data->mlx, WALL_XPM, &img_w, &img_h);
	data->collectible = mlx_xpm_file_to_image(data->mlx, C_XPM, &img_w, &img_h);
	data->background = mlx_xpm_file_to_image(data->mlx, G_XPM, &img_w, &img_h);
	data->foe = mlx_xpm_file_to_image(data->mlx, FOE_XPM, &img_w, &img_h);
}

void	image_to_screen2(t_data *data, int y, int x)
{
	if (data->map[y][x] == '1')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->wall, x * 64, y
			* 64);
	else
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->background, x
			* 64, y * 64);
		if (data->map[y][x] == 'P' && data->p_right)
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->player_r,
				x * 64, y * 64);
		if (data->map[y][x] == 'P' && !data->p_right)
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->player_l,
				x * 64, y * 64);
		if (data->map[y][x] == 'C')
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->collectible,
				x * 64, y * 64);
		if (data->map[y][x] == 'E')
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->exit,
				x * 64, y * 64);
		if (data->map[y][x] == 'F')
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->foe,
				x * 64, y * 64);
	}
	mlx_string_put(data->mlx, data->mlx_win, 20, 40, 0xFF10AB,
		data->player_step_screen);
}

void	image_to_screen(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y <= data->map_y - 1)
	{
		x = 0;
		while (x <= data->map_x - 1)
		{
			image_to_screen2(data, y, x);
			x++;
		}
		y++;
	}
}
