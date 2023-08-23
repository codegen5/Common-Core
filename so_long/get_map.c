/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 09:46:13 by msamilog          #+#    #+#             */
/*   Updated: 2023/08/23 18:06:44 by msamilog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_map(t_data *data, char *map_name, char *str)
{
	char	*buff;
	int		fd;
	char	*temp;

	buff = NULL;
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		ft_exit("Invalid file");
	str = get_next_line(fd);
	if (str == NULL)
		ft_exit("File is empty");
	while (str)
	{
		temp = ft_strjoin(buff, str);
		free(buff);
		buff = temp;
		free(str);
		str = get_next_line(fd);
		data->map_y_control++;
	}
	close(fd);
	data->map = ft_split(buff, '\n');
	data->c_map = ft_split(buff, '\n');
	free(buff);
}
