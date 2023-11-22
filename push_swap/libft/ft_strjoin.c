/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 19:11:52 by msamilog          #+#    #+#             */
/*   Updated: 2023/11/22 13:49:05 by msamilog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int	size;
	char	*d;
	int	i;
	int	j;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	d = (char *)malloc(size * sizeof(char));
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
