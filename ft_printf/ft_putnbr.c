/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 18:58:38 by msamilog          #+#    #+#             */
/*   Updated: 2023/07/09 18:58:38 by msamilog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nbr)
{
	static char	buffer[16];
	int			i;
	int			x;
	long			num;

	i = 0;
	x = 0;
	num = nbr;
	if (num == 0)
		return (write(1, "0", 1));
	if (num < 0)
	{
		x += write(1, "-", 1);
		num = -num;
	}
	while (num)
	{
		buffer[i++] = num % 10 + '0';
		num /= 10;
	}
	while (i--)
		x += write(1, &buffer[i], 1);
	return (x);
}
