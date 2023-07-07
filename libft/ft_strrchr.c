/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:26:48 by msamilog          #+#    #+#             */
/*   Updated: 2023/05/16 17:26:48 by msamilog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	val;
	int				i;

	i = ft_strlen(s);
	val = c;
	while (&s[i] >= s)
	{
		if (s[i] == val)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}
