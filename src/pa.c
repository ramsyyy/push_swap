/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaga <raaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:50:19 by raaga             #+#    #+#             */
/*   Updated: 2022/02/23 13:26:41 by raaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_pb_utils(t_list **b, t_list **a, t_list *tmp)
{
	if ((*b) == NULL)
	{
		back_to_start(a);
		tmp = (*a);
		*b = tmp;
		if ((*a)->next != NULL)
		{
			(*a) = (*a)->next;
			(*a)->prev = NULL;
		}
		back_to_start(a);
		(*b)->next = NULL;
		(*b)->prev = NULL;
	}
	else if (taille_list(*a) == 1)
	{
		tmp = *a;
		back_to_start(b);
		(*b)->prev = tmp;
		(*b)->prev->next = (*b);
		(*b)->prev->prev = NULL;
		(*a) = NULL;
	}
}

void	ft_pb(t_list **b, t_list **a)
{
	t_list	*tmp;

	tmp = NULL;
	if (*a == NULL)
		return ;
	if ((*b) == NULL || taille_list(*a) == 1)
		ft_pb_utils(b, a, tmp);
	else
	{
		back_to_start(a);
		tmp = *a;
		back_to_start(b);
		(*b)->prev = tmp;
		if ((*a)->next != NULL)
		{
			(*a) = (*a)->next;
			(*a)->prev = NULL;
		}
		(*b)->prev->prev = NULL;
		(*b)->prev->next = (*b);
	}
	back_to_start(a);
	back_to_start(b);
}

void	ft_ra(t_list **a)
{
	t_list	*tmp;

	if ((*a) == NULL)
		return ;
	if ((*a)->prev != NULL)
		back_to_start(a);
	tmp = *a;
	(*a)->next->prev = NULL;
	go_to_end(a);
	(*a)->next = tmp;
	(*a)->next->prev = *a;
	(*a)->next->next = NULL;
	back_to_start(a);
}

void	ft_rra(t_list **a)
{
	t_list	*tmp;

	if ((*a) == NULL || taille_list(*a) == 1)
		return ;
	if ((*a)->next != NULL)
		go_to_end(a);
	tmp = *a;
	(*a)->prev->next = NULL;
	back_to_start(a);
	(*a)->prev = tmp;
	(*a)->prev->next = *a;
	(*a) = (*a)->prev;
	(*a)->prev = NULL;
	go_to_end(a);
	back_to_start(a);
}
