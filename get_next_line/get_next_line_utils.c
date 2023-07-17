/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 00:30:40 by msamilog          #+#    #+#             */
/*   Updated: 2023/07/17 06:03:34 by msamilog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*d;

	if (ft_strlen(s) < start)
	{
		d = (char *)malloc(sizeof(char));
		if (!d)
			return (NULL);
		*d = '\0';
		return (d);
	}
	else
	{
		if (ft_strlen(s) < start + len)
			len = ft_strlen(s) - start;
		d = (char *)malloc((len + 1) * sizeof(char));
		if (!d)
			return (NULL);
		i = -1;
		while (++i < len)
			*(d + i) = *(s + start + i);
		*(d + i) = '\0';
		return (d);
	}
	return (NULL);
}
