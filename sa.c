/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaga <raaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 13:00:43 by raaga             #+#    #+#             */
/*   Updated: 2022/01/26 20:52:00 by raaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sasb(t_list *a)
{
	int	tmp;

	if (a->prev == NULL)
	{
		tmp = a->nb;
		a->nb = a->next->nb;
		a->next->nb = tmp;
	}
}

void	ss(t_list *a, t_list *b)
{
	sasb(a);
	sasb(b);
}

void	pb(t_list **b, t_list **a)
{
	t_list	*tmp;

	if (*a == NULL)
		return ;
	if ((*b) == NULL)
	{
		*b = ft_lstnew((*a)->nb);
		if ((*a)->next != NULL)
			*a = (*a)->next;
			(*a)->prev = NULL;
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
			*a = (*a)->next;
		(*a)->prev = NULL;
		else
			*a = NULL;
	}
}

void	pa(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (*b == NULL)
		return ;
	if ((*a) == NULL)
	{
		*a = ft_lstnew((*b)->nb);
		if ((*b)->next != NULL)
			*b = (*b)->next;
		(*b)->prev = NULL;
		else
			*b = NULL;
	}
	else
	{
		back_to_start(a);
		*a = (*a)->prev;
		*a = ft_lstnew((*b)->nb);
		if ((*b)->next != NULL)
			*b = (*b)->next;
		(*b)->prev = NULL;
		else
			*b = NULL;
	}
}