/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:13:33 by msamilog          #+#    #+#             */
/*   Updated: 2023/11/19 15:05:08 by msamilog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_strings(char **strings)
{
	size_t	count;

	count = 0;
	while (strings[count])
		free(strings[count++]);
	free(strings);
}
