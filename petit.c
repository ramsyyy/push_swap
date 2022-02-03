/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   petit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaga <raaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:40:12 by raaga             #+#    #+#             */
/*   Updated: 2022/02/03 20:03:31 by raaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	decroissant(t_list *a)
{
	while (a != NULL)
	{
		if (a->next == NULL)
			break ;
		if (a->nb < a ->next->nb)
			return (0);
		a = a->next;
	}
	return (1);
}

void	petit(t_list **a, t_list **b)
{
	while (check_list(*a, *b) == 0)
	{
		while (check_list_a(*a) == 0)
		{
			if (((*a)->nb > (*a)->next->nb && (*a)->next->nb > list_dernier(*a)) || ((*a)->nb < (*a)->next->nb && (*a)->nb < list_dernier(*a))  || ((*a)->nb > (*a)->next->nb && (*a)->nb < list_dernier(*a)))
				sa(*a);
			else if ((*a)->nb > list_dernier(*a) && (*a)->nb < (*a)->next->nb)
				rra(a);
			else if ((*a)->nb > list_dernier(*a))
				ra(a);
			if (check_list_a(*a) != 0)
				break ;
			if ((*a)->nb < (*a)->next->nb && (*a)->nb < list_dernier(*a))
				pb(b, a);
			back_to_start(a);
			if (b != NULL)
				back_to_start(b);
			if (*b != NULL)
			{
				if ((*b)->next != NULL)
				{
					if ((*b)->nb < (*b)->next->nb && (*a)->nb > (*a)->next->nb)
						ss(*a, *b);
					if ((*a)->nb > list_dernier(*a) && (*b)->nb < list_dernier(*b))
					{
						rrr(a, b);
					}
					if ((*a)->nb > list_dernier(*a) && (*b)->nb < list_dernier(*b))
						rr(a, b);
				}
			}
			
		}
		if (check_list_b(*b) == 0)
		{
			if (((*b)->nb < (*b)->next->nb && (*b)->next->nb < list_dernier(*b)) || ((*b)->nb > (*b)->next->nb && (*b)->nb > list_dernier(*b)) || ((*b)->nb < (*b)->next->nb && (*b)->nb > list_dernier(*b)))
				sb(*b);
			else if ((*b)->nb < list_dernier(*b) && (*b)->nb > (*b)->next->nb)
			{
				rrb(b);
				back_to_start(b);
			}
			else if ((*a)->nb < list_dernier(*a))
				rb(b);
		}
		if (*b != NULL)
			pa(a, b);
	}
}

void    petit_inverser(t_list **a, t_list **b)
{
	while (check_list(*a, *b) == 0)
	{
		while (check_list_b(*b) == 0)
		{
			if (((*b)->nb < (*b)->next->nb && (*b)->next->nb < list_dernier(*b)) || ((*b)->nb > (*b)->next->nb && (*b)->nb > list_dernier(*b))  || ((*b)->nb < (*b)->next->nb && (*b)->nb > list_dernier(*b)))
				sb(*b);
			else if ((*b)->nb > list_dernier(*b) && (*b)->nb < (*b)->next->nb)
				rrb(b);
			else if ((*b)->nb > list_dernier(*b))
				rb(b);
			if (check_list_b(*b) != 0)
				break ;
			if ((*b)->nb < (*b)->next->nb && (*b)->nb < list_dernier(*b))
				pa(a, b);
			back_to_start(a);
			if (b != NULL)
				back_to_start(b);
			if (*a != NULL)
			{
				if ((*a)->next != NULL)
				{
					if ((*a)->nb < (*a)->next->nb && (*b)->nb > (*b)->next->nb)
						ss(*b, *a);
					if ((*b)->nb > list_dernier(*b) && (*a)->nb < list_dernier(*a))
					{
						rrr(a, b);
					}
					if ((*b)->nb > list_dernier(*b) && (*a)->nb < list_dernier(*a))
						rr(a, b);
				}
			}
		}
		if (check_list_a(*a) == 0)
		{
			if (((*b)->nb < (*b)->next->nb && (*b)->next->nb < list_dernier(*b)) || ((*b)->nb > (*b)->next->nb && (*b)->nb > list_dernier(*b)) || ((*b)->nb < (*b)->next->nb && (*b)->nb > list_dernier(*b)))
				sb(*b);
			else if ((*b)->nb < list_dernier(*b) && (*b)->nb > (*b)->next->nb)
			{
				rrb(b);
				back_to_start(b);
			}
			else if ((*a)->nb < list_dernier(*a))
				rb(b);
		}
		if (*b != NULL)
			pa(a, b);
	}	
}
