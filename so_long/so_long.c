/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 02:20:19 by msamilog          #+#    #+#             */
/*   Updated: 2023/08/14 16:19:55 by msamilog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	size_t	x;
	size_t	y;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
	&img.line_length, &img.endian);
	x = 500;
	y = 300;
	while (x < 600)
	{
		my_mlx_pixel_put(&img, x++, y++, 0x00FF00FF);
		mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	}
	while (y < 500)
	{
		my_mlx_pixel_put(&img, x--, y++, 0x00FF00FF);
		mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	}
	while (x > 400)
	{
		my_mlx_pixel_put(&img, x--, y--, 0x00FF00FF);
		mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	}
	while (y > 300)
	{
		my_mlx_pixel_put(&img, x++, y--, 0x00FF00FF);
		mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	}
	mlx_loop(mlx);
}
