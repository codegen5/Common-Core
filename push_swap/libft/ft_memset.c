/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:26:48 by msamilog          #+#    #+#             */
/*   Updated: 2023/11/22 13:49:05 by msamilog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, int len)
{
	int			i;
	unsigned char	*p;
	unsigned char	val;

	p = (unsigned char *)b;
	val = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		p[i] = val;
		i++;
	}
	return (b);
}
