/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:20:36 by msamilog          #+#    #+#             */
/*   Updated: 2023/11/12 19:32:24 by msamilog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_list
{
	int				data;
	struct s_list	*next;
	struct s_list	*prev;
}t_list;

typedef struct s_stack
{
	t_list	*head_a;
	t_list	*head_b;
	int		*sorted;
	int		a_size;
	int		b_size;	
}t_stack;

void	check_error(int ac, char **av);
void	free_strings(char **strings);
void	convert_arg(int ac, char **av, int *num_array);
int		ft_atoint(char *str);

#endif