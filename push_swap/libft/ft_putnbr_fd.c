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

#include "libft.h"

static inline
void	ft_putchar(char a, int fd)
{
	write(fd, &a, 1);
}

static inline
void	ft_putnbr(int nb, int fd)
{
	if (nb == -2147483648)
	{
		ft_putchar('-', fd);
		ft_putchar('2', fd);
		ft_putnbr(147483648, fd);
	}
	else if (nb < 0)
	{
		ft_putchar('-', fd);
		nb = -nb;
		ft_putnbr(nb, fd);
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10, fd);
		ft_putnbr(nb % 10, fd);
	}
	else
	{
		ft_putchar(nb + 48, fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	ft_putnbr(n, fd);
}
