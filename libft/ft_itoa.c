/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 15:28:00 by msamilog          #+#    #+#             */
/*   Updated: 2023/07/09 15:28:00 by msamilog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*res;
	int		tmp;
	int		i;

	i = 1;
	tmp = n;
	while (tmp && i++)
		tmp /= 10;
	res = (char *)malloc(sizeof(char) * ((n < 0) + i + (n == 0)));
	if (!res)
		return (NULL);
	res += (n < 0) + i - 1 + (n == 0);
	*res = '\0';
	if (n == 0)
		*(--res) = '0';
	i = (n >= 0) * 2 - 1;
	while (n)
	{
		*(--res) = n % (i * 10) * i + '0';
		n /= 10;
	}
	if (i < 0)
		*(--res) = '-';
	return (res);
}
