/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:06:33 by msamilog          #+#    #+#             */
/*   Updated: 2023/11/22 13:53:56 by msamilog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, int start, int len)
{
	int			i;
	char		*d;

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
