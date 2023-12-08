/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:20:36 by msamilog          #+#    #+#             */
/*   Updated: 2023/12/08 16:24:51 by msamilog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int		*stack_a;
	int		*stack_b;
	int		*index_a;
	int		a_size;
	int		b_size;	
}	t_stack;

void	check_error(int ac, char **av, t_stack *s);
void	ft_sort(t_stack *s);
void	push_minus_3(t_stack *s);
int		max_num_stack_b(t_stack *s);
void	rotate_a(t_stack *s, int r);
void	rotate_b(t_stack *s, int r);
void	rotate_both(t_stack *s, int *r_a, int *r_b, int direction);
void	tiny_sort(t_stack *s);
void	final_push(t_stack *s);

int		find_index_highest(int *arr, int size);
int		is_sorted(int *arr, size_t size);
void	bubble_sort_inv(int *arr, size_t size);
int		is_b_min_max(t_stack *s, int num);
int		find_rot_b(t_stack *s, int num);
int		threesort_rot_moves(t_stack *s);
int		ft_atoint(char *str);
int		ft_abs(int n);
int		find_neg_low(t_stack *s, int num, int *n);
int		find_pos_low(t_stack *s, int num, int *p);
int		get_move_count(t_stack *s, int i);
int		get_shortest_index(t_stack *s);

void	convert_arg(int ac, char **av, t_stack *s);
void	ft_init(t_stack *s);

void	free_strings(char **strings);
void	free_all(t_stack *s);

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