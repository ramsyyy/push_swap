/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaga <raaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:50:19 by raaga             #+#    #+#             */
/*   Updated: 2022/02/16 18:26:08 by raaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pb(t_list **b, t_list **a)
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
		{
			tmp  = *a;
			(*a) = (*a)->next;
			(*a)->prev = NULL;
		}
	}
	else
	{
		back_to_start(b);
		tmp = *b;
		*b = (*b)->prev;
		*b = ft_lstnew((*a)->nb);
		(*b)->next = tmp;
		(*b)->next->prev = *b;
		if ((*a)->next != NULL)
		{
			*a = (*a)->next;
			(*a)->prev = NULL;
		}
		else
			*a = NULL;
	}
}

void	ft_ra(t_list **a)
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
	free((*a)->prev);
}

void	ft_rra(t_list **a)
{
	int	tmp;

	if ((*a) == NULL)
		return ;
	if ((*a)->next != NULL)
		go_to_end(a);
	tmp = (*a)->nb;
	back_to_start(a);
	(*a)->prev = ft_lstnew(tmp);
	(*a)->prev->next = *a;
	(*a)->prev->prev = NULL;
	go_to_end(a);
	*a = (*a)->prev;
	(*a)->next = NULL;
	back_to_start(a);
}
