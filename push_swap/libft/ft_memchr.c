/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:28:41 by msamilog          #+#    #+#             */
/*   Updated: 2023/07/04 12:28:41 by msamilog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;
	unsigned char		val;

	p = (unsigned char *)s;
	val = (unsigned char)c;
	while (n--)
	{
		if (*p == val)
			return ((void *)p);
		p++;
	}
	return (NULL);
}
