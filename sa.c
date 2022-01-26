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
	//int	tmp;

	back_to_start(&a);
	if ((*b) == NULL)
	{
		*b = ft_lstnew((*a)->nb);
		(*b)->prev = NULL;
		(*b)->next = NULL;
		*a = NULL;
	}
	//printf("%d\n", (*b)->nb);
	/*else
	{
		b = go_to_end(b);
		while (b != NULL)
		{
			tmp = b->nb;
			b = b->next;
			b = ft_lstnew(tmp);
			b = b->prev->prev;
		}
	}*/
}