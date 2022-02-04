/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grand.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaga <raaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:16:29 by raaga             #+#    #+#             */
/*   Updated: 2022/02/04 22:05:53 by raaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	distance(int var, t_list *a)
{
	int	tmp;

	tmp = 0;
	if (var == 1)
	{
		return (1);
	}
	if (var > taille_list(a) / 2)
	{
		while (var <= taille_list(a))
		{
			tmp++;
			var++;
		}
	}
	else
	{
		while (var > 1)
		{
			tmp++;
			var--;
		}
	}
	return (tmp);
}

int	list_i(t_list *a, int	place)
{
	while (place > 0)
	{
		a = a->next;
	}
	return (a->nb);
}

void	grand(t_list **a, t_list **b)
{
	int	first;
	int	second;

	first = min_first(*a);
	second = min_second(*a);
	if (check_list(*a, *b) == 0)
	{
		if (check_list_a(*a) == 0)
		{
			while (taille_list(*a) > 5)
			{
				first = min_first(*a);
				second = min_second(*a);
				if (distance(first, *a) < distance(second, *a))
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
				else if (*b != NULL && (*b)->next != NULL && check_list_b(*b) == 0 && (*b)->nb < list_dernier(*b)) 
				{
					rb(b);
				}
			
				
			}
			moyen(a, b);
		}
	}
}
