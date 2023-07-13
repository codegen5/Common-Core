/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 11:28:55 by msamilog          #+#    #+#             */
/*   Updated: 2023/07/13 15:02:59 by msamilog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline
int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

static inline
int	ft_putstr(char *str)
{
	int	i;

	if (!str)
		return (write(1, "(null)", 6));
	i = 0;
	while (str[i])
		i += write(1, &str[i], 1);
	return (i);
}

static inline
int	ft_puthexa(unsigned int nbr, char *list)
{
	static char	buffer[16];
	int			i;
	int			x;

	if (nbr == 0)
		return (write(1, "0", 1));
	i = 0;
	x = 0;
	while (nbr)
	{
		buffer[i++] = list[nbr % 16];
		nbr /= 16;
	}
	while (i--)
		x += write(1, &buffer[i], 1);
	return (x);
}

static inline
int	ft_format(char c, va_list ap)
{
	if (c == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (c == 'p')
		return (ft_putptr(va_arg(ap, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	else if (c == 'u')
		return (ft_putdec(va_arg(ap, unsigned int)));
	else if (c == 'x')
		return (ft_puthexa(va_arg(ap, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_puthexa(va_arg(ap, unsigned int), "0123456789ABCDEF"));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		y;

	va_start(ap, format);
	i = 0;
	y = 0;
	while (format[i])
	{
		if (format[i] == '%')
			y += ft_format(format[++i], ap);
		else
			y += write(1, &format[i], 1);
		i++;
	}
	va_end(ap);
	return (y);
}
