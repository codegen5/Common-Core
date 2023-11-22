/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:26:48 by msamilog          #+#    #+#             */
/*   Updated: 2023/11/22 13:49:05 by msamilog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *dst, const char *src, int dstsize)
{
	int	i;
	int	y;
	int	len_d;
	int	len_s;

	len_d = ft_strlen(dst);
	len_s = ft_strlen(src);
	if (dstsize <= len_d)
		return (len_s + dstsize);
	i = len_d;
	y = 0;
	while (src[y] && i < dstsize - 1)
	{
		dst[i] = src[y];
		i++;
		y++;
	}
	dst[i] = '\0';
	return (len_s + len_d);
}
