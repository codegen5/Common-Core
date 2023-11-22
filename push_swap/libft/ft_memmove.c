/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:01:29 by msamilog          #+#    #+#             */
/*   Updated: 2023/11/22 13:49:05 by msamilog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, int len)
{
	char		*d;
	const char	*s;

	if (!dst && !src)
		return (0);
	d = dst;
	s = src;
	if (s < d && s + len > d)
	{
		s += len;
		d += len;
		while (len--)
			*--d = *--s;
	}
	else
		ft_memcpy(d, s, len);
	return (dst);
}
