/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:49:18 by msamilog          #+#    #+#             */
/*   Updated: 2023/07/13 18:49:18 by msamilog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putdec(unsigned int nbr)
{
	static char	buffer[16];
	int	i;
	int	x;

	if (nbr == 0)
		return (write(1, "0", 1));
	i = 0;
	x = 0;
	while (nbr)
	{
		buffer[i++] = nbr % 10 + '0';
		nbr /= 10;
	}
	while (i--)
		x += write(1, &buffer[i], 1);
	return (x);
}
