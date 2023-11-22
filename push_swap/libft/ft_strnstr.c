/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:32:41 by msamilog          #+#    #+#             */
/*   Updated: 2023/11/22 13:49:05 by msamilog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, int len)
{
	int	i;
	int	j;

	if (!*needle)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		if (haystack[i] == *needle)
		{
			j = 0;
			while (needle[j] && i + j < len
				&& haystack[i + j] == needle[j])
				j++;
			if (!needle[j])
				return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}
