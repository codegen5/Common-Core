/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operations1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:02:43 by msamilog          #+#    #+#             */
/*   Updated: 2023/11/17 18:42:58 by msamilog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *s)
{
	int	temp;

	if (s->a_size < 2)
		return ;
	temp = s->head_a->data;
	s->head_a->data = s->head_a->next->data;
	s->head_a->next->data = temp;
	write(1, "sa\n", 3);
}

void	sb(t_stack *s)
{
	int	temp;

	if (s->b_size < 2)
		return ;
	temp = s->head_b->data;
	s->head_b->data = s->head_b->next->data;
	s->head_b->next->data = temp;
	write(1, "sb\n", 3);
}

void	ss(t_stack *s)
{
	int	temp;

	if (s->a_size < 2 || s->b_size < 2)
		return ;
	temp = s->head_a->data;
	s->head_a->data = s->head_a->next->data;
	s->head_a->next->data = temp;
	temp = s->head_b->data;
	s->head_b->data = s->head_b->next->data;
	s->head_b->next->data = temp;
	write(1, "ss\n", 3);
}

void	pa(t_stack *s)
{
	t_list	*temp;

	if (s->b_size)
	{
		if (!(s->a_size))
		{
			s->head_a = malloc(sizeof(t_list));
			if (!(s->head_a))
				return ;
			s->head_a->data = s->head_b->data;
			s->head_a->next = s->head_a;
			s->head_a->prev = s->head_a;
		}
		else
		{
			temp = malloc(sizeof(t_list));
			if (!temp)
				return ;
			temp->data = s->head_b->data;
			temp->next = s->head_a;
			temp->prev = s->head_a->prev;
			s->head_a->prev->next = temp;
			s->head_a->prev = temp;
			s->head_a = temp;
		}
	}
}

void	pb(t_stack *s)
{
	
}