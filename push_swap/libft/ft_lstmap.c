/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:06:32 by msamilog          #+#    #+#             */
/*   Updated: 2023/10/28 21:13:02 by msamilog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, int (f)(int), void (*del)(int))
{
	t_list	*new;
	t_list	*temp;
	int		cont;

	if (lst == NULL)
		return (NULL);
	new = NULL;
	while (lst)
	{
		cont = f(lst->content);
		temp = ft_lstnew(cont);
		if (temp == NULL)
		{
			del(cont);
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, temp);
		lst = lst->next;
	}
	return (new);
}
