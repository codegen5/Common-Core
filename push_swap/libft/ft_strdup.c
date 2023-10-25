/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:59:57 by msamilog          #+#    #+#             */
/*   Updated: 2023/05/16 12:59:57 by msamilog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		w;
	int		a;
	char	*s2;

	w = ft_strlen(s1);
	s2 = (char *)malloc(sizeof(char) * (w + 1));
	if (s2 == NULL)
		return (NULL);
	a = 0;
	while (s1[a] != '\0')
	{
		s2[a] = s1[a];
		a++;
	}
	s2[a] = '\0';
	return (s2);
}
