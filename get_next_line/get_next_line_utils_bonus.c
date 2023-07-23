/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 02:35:40 by msamilog          #+#    #+#             */
/*   Updated: 2023/07/23 07:53:51 by msamilog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	val;

	val = c;
	while (*s && val != *s)
		s++;
	if (val == *s)
		return ((char *)s);
	return (NULL);
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*d;
	size_t	i;
	size_t	j;

	d = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!d)
		return (NULL);
	i = 0;
	while (*(s1 + i))
	{
		*(d + i) = *(s1 + i);
		i++;
	}
	j = 0;
	while (*(s2 + j))
	{
		*(d + i + j) = *(s2 + j);
		j++;
	}
	*(d + i + j) = '\0';
	return (d);
}
