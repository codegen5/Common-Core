/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 19:29:15 by msamilog          #+#    #+#             */
/*   Updated: 2023/11/22 13:49:05 by msamilog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline
char	**ft_deallocate(char **result, int i)
{
	int	n;

	n = 0;
	while (n < i)
		free(result[n++]);
	free(result);
	return (NULL);
}

static inline
char	*ft_get_word(const char *s, char c, int word_count)
{
	static int	i = 0;
	static int	j = 0;
	char			*result;

	while (s[i] && s[i] == c)
		i++;
	j = i;
	while (s[i])
	{
		if (s[i] == c)
		{
			result = ft_substr(s, j, i - j);
			if (word_count == 0)
				i = 0;
			return (result);
		}
		i++;
	}
	result = ft_substr(s, j, i - j);
	i = 0;
	return (result);
}

static inline
int	ft_count_words(char const *s, char c)
{
	int	y;
	int	word_count;
	int		is_word;

	is_word = 0;
	word_count = 0;
	y = 0;
	while (s[y] && s[y] == c)
		y++;
	while (s[y])
	{
		if (s[y] != c && is_word == 0)
		{
			is_word = 1;
			word_count++;
		}
		else if (s[y] == c)
			is_word = 0;
		y++;
	}
	return (word_count);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int	word_count;
	int	i;

	if (!s)
		return (NULL);
	word_count = ft_count_words(s, c);
	result = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (word_count--)
	{
		result[i] = ft_get_word(s, c, word_count);
		if (!result[i])
			return (ft_deallocate(result, i));
		i++;
	}
	result[i] = NULL;
	return (result);
}
