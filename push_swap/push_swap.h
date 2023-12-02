/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:20:36 by msamilog          #+#    #+#             */
/*   Updated: 2023/12/03 00:51:20 by msamilog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <stdio.h>

typedef struct s_stack
{
	int		*stack_a;
	int		*stack_b;
	int		*index;
	int		a_size;
	int		b_size;	
}t_stack;

void	check_error(int ac, char **av, t_stack *s);
void	convert_arg(int ac, char **av, t_stack *s);
void	push_pull(t_stack *s);
int		find_next(t_stack *s, int j);

int		find_highest(t_stack *s);
void	free_strings(char **strings);
int		is_sorted(int *arr, size_t size);
void	bubble_sort(int *arr, size_t size);
int		ft_atoint(char *str);

void	sa(t_stack *s);
void	sb(t_stack *s);
void	ss(t_stack *s);
void	pa(t_stack *s);
void	pb(t_stack *s);
void	ra(t_stack *s);
void	rb(t_stack *s);
void	rr(t_stack *s);
void	rra(t_stack *s);
void	rrb(t_stack *s);
void	rrr(t_stack *s);

#endif