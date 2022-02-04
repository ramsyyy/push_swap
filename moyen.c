/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moyen.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaga <raaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:41:03 by raaga             #+#    #+#             */
/*   Updated: 2022/02/04 22:05:36 by raaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_first(t_list *a)
{
	int	tmp;
	int	i;
	int	pos;

	pos = 0;
	i = 1;
	while (a != NULL)
	{
		if (i == 1)
			tmp = a->nb;
		if (tmp >= a->nb)
		{
			pos = i;
			tmp = a->nb;
		}
		if (a->next == NULL)
			break ;
		a = a->next;
		i++;
	}
	return (pos);
}

int	min_second(t_list *a)
{
	int min;
	int	tmp;
	int	i;
	int	pos;

	min = min_first(a);
	pos = 1;
	i = 1;
	tmp = a->nb;
	while (a != NULL)
	{	
		if (a->next == NULL)
			break ;
		if (i == min)
		{
			i++;
			a = a->next;
		}
		if (tmp >= a->nb)
		{
			pos = i;
			tmp = a->nb;
		}
		a = a->next;
		i++;
	}
	return (pos);
}

void	moyen(t_list **a, t_list **b)
{
	int	first;
	int	second;

	if (check_list(*a, *b) == 0)
	{
		while (taille_list(*a) > 3)
		{
			first = min_first(*a);
			second = min_second(*a);
			if (taille_list(*a) == 4)
			{
				if (first > taille_list(*a) / 2)
				{
					while (first <= taille_list(*a))
					{
						rra(a);
						first++;
					}
					pb(b, a);
				}
				else
				{
					while (first > 1)
					{
						ra(a);
						first--;
					}
					pb(b, a);
				}
			}
			else if (distance(first, *a) <= distance(second, *a))
			{
				if (first > taille_list(*a) / 2)
				{
					while (first <= taille_list(*a))
					{
						rra(a);
						first++;
					}
					pb(b, a);
				}
				else
				{
					while (first > 1)
					{
						ra(a);
						first--;
					}
					pb(b, a);
				}
			}
			else
			{
				if (second > taille_list(*a) / 2)
				{
					while (second <= taille_list(*a))
					{
						rra(a);
						second++;
					}
					pb(b, a);
				}
				else
				{
					while (second > 1)
					{
						ra(a);
						second--;
					}
					pb(b, a);
				}
			}
			if (*b != NULL && (*b)->next != NULL && check_list_b(*b) == 0 && (*b)->nb < (*b)->next->nb)
					sb(*b);
			else if (*b != NULL && (*b)->next != NULL && check_list_b(*b) == 0)
			{
				rb(b);
			}
			
		}
		display_list(*b);
		petit(a, b);
		while (taille_list(*b) > 0)
			pa(a, b);
	}
}
