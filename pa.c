/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaga <raaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:50:19 by raaga             #+#    #+#             */
/*   Updated: 2022/01/28 21:57:27 by raaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_list **b, t_list **a)
{
	t_list	*tmp;

	if (*a == NULL)
		return ;
	if ((*b) == NULL)
	{
		*b = ft_lstnew((*a)->nb);
		if ((*a)->next != NULL)
		{
			*a = (*a)->next;
			(*a)->prev = NULL;
		}
		else
			*a = NULL;
	}
	else
	{
		tmp = *b;
		*b = (*b)->prev;
		*b = ft_lstnew((*a)->nb);
		(*b)->next = tmp;
		if ((*a)->next != NULL)
		{
			*a = (*a)->next;
			(*a)->prev = NULL;
		}
		else
			*a = NULL;
	}
}

void	ra(t_list **a)
{
	t_list	*tmp;

	if ((*a) == NULL)
		return ;
	if ((*a)->prev != NULL)
		back_to_start(a);
	tmp = *a;
	go_to_end(a);
	(*a)->next = ft_lstnew(tmp->nb);
	(*a)->next->prev = *a;
	(*a)->next->next = NULL;
	back_to_start(a);
	*a = (*a)->next;
	(*a)->prev = NULL;
	free(tmp);
}

void	rr(t_list **a, t_list **b)
{
	ra(a);
	ra(b);
}

void	rra(t_list **a)
{
	t_list	*tmp;

	if ((*a) == NULL)
		return ;
	if ((*a)->next != NULL)
		go_to_end(a);
	tmp = *a;
	back_to_start(a);
	(*a)->prev = ft_lstnew(tmp->nb);
	(*a)->prev->next = *a;
	(*a)->prev->prev = NULL;
	go_to_end(a);
	*a = (*a)->prev;
	(*a)->next = NULL;
	free(tmp);
}

void	rrr(t_list **a, t_list **b)
{
	rra(a);
	rra(b);
}
