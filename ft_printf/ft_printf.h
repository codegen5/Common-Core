/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 11:31:09 by msamilog          #+#    #+#             */
/*   Updated: 2023/07/15 04:32:49 by msamilog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_putstr(char *str);
int	ft_putnbr(int nb);
int	ft_putudec(unsigned int nbr);
int	ft_puthexa(unsigned int nbr, char *list);
int	ft_putptr(void *ptr);
int	ft_printf(const char *format, ...);

#endif
