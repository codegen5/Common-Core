/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:20:36 by msamilog          #+#    #+#             */
/*   Updated: 2023/10/30 23:52:07 by msamilog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_stack
{
	t_list	*head_a;
	t_list	*head_b;
	int		*sorted;
	int		a_size;
	int		b_size;	
}t_stack;

void	check_error(int ac, char **av, t_list *lst);
void	stack_init(int ac, char **av, t_list *lst);

#endif