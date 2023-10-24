/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 09:46:13 by msamilog          #+#    #+#             */
/*   Updated: 2023/10/24 14:18:53 by msamilog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_xpm_cont2(t_data *data)
{
	int	fd;

	fd = open(PL_R_XPM, O_RDONLY);
	if (fd < 0)
		ft_error("CAN'T OPEN XPM!\n", data);
	close(fd);
	fd = open(PL_L_XPM, O_RDONLY);
	if (fd < 0)
		ft_error("CAN'T OPEN XPM!\n", data);
	close(fd);
	fd = open(FOE_XPM, O_RDONLY);
	if (fd < 0)
		ft_error("CAN'T OPEN XPM!\n", data);
	close(fd);
}

void	ft_xpm_cont1(t_data *data)
{
	int	fd;

	fd = open(EX_XPM, O_RDONLY);
	if (fd < 0)
		ft_error("CAN'T OPEN XPM!\n", data);
	close(fd);
	fd = open(C_XPM, O_RDONLY);
	if (fd < 0)
		ft_error("CAN'T OPEN XPM!\n", data);
	close(fd);
	fd = open(WALL_XPM, O_RDONLY);
	if (fd < 0)
		ft_error("CAN'T OPEN XPM!\n", data);
	close(fd);
	fd = open(G_XPM, O_RDONLY);
	if (fd < 0)
		ft_error("CAN'T OPEN XPM!\n", data);
	close(fd);
}

void	ft_map(t_data *data, char *map)
{
	char	*str;

	str = NULL;
	data->p_count = 0;
	data->e_count = 0;
	data->f_count = 0;
	get_map(data, map, str);
	free(str);
	invalid_mapname(map, data);
	element_check(data);
	is_rectangular(data);
	wall_ok(data);
	another_coin(data);
	ft_xpm_cont1(data);
	ft_xpm_cont2(data);
}

void	ft_win_and_hook(t_data *data)
{
	data->mlx = mlx_init();
	find_player(data, 'P');
	if (data->map_y > 20)
		ft_error("Map doesn't fit to screen!\n", data);
	if (data->map_x > 40)
		ft_error("Map doesn't fit to screen!\n", data);
	data->mlx_win = mlx_new_window(data->mlx, (data->map_x) * 64, \
	(data->map_y) * 64, "./so_long");
	image_initialize(data);
	image_to_screen(data);
	mlx_hook(data->mlx_win, 17, 0, ft_close_window, data);
	mlx_hook(data->mlx_win, 2, 0, handle_key_press, data);
	mlx_loop_hook(data->mlx, foe_random_move, data);
	mlx_loop(data->mlx);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac == 2)
	{
		srand(time(NULL));
		data = malloc(sizeof(t_data));
		if (!data)
			ft_exit("Couldn't allocate memory!\n");
		data->player_step = 0;
		data->collectible_count_copy = 0;
		data->collectible_count = 0;
		data->player_collected = 0;
		data->map_y_control = 0;
		data->p_right = 1;
		ft_map(data, av[1]);
		step_counter(data);
		ft_win_and_hook(data);
	}
	else
		ft_exit("Invalid argument count!\n");
}
