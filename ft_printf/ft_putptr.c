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

int	ft_putptr(void *ptr)
{
	static char	buffer[32];
	int			x;
	unsigned long		temp;
	int			i;

	temp = (unsigned long)ptr;
	if (!temp)
		return (write(1, "0x0", 3));
	x = 0;
	i = 0;
	while (temp)
	{
		buffer[i++] = "0123456789abcdef"[temp % 16];
		temp = temp / 16;
	}
	x += write(1, "0x", 2);
	while (i--)
		x += write(1, &buffer[i], 1);
	return (x);
}
