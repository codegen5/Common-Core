/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:32:41 by msamilog          #+#    #+#             */
/*   Updated: 2023/05/16 18:16:41 by msamilog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	y;
	size_t	n;

	n = 1;
	i = 0;
	if (!needle[i])
		return (haystack);
	while (haystack[i])
	{
		y = 0;
		while (haystack[i + y] == needle[y])
		{
			if (n == len || !needle[y + 1])
				return (haystack + i);
			y++;
			n++;
		}
		i++;
	}
	return (0);
}
