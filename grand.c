/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grand.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaga <raaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:16:29 by raaga             #+#    #+#             */
/*   Updated: 2022/02/08 20:19:28 by raaga            ###   ########.fr       */
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

void	grand(t_list **a, t_list **b, t_moy x)
{
	int	first;
	int	second;

	(void)x;
	if (check_list(*a, *b) == 0)
	{
		if (check_list_a(*a) == 0)
		{
			while (taille_list(*a) >= 5)
			{
				first = min_first(*a);
				second = min_second(*a);				
				if (distance(first, *a) <= distance(second, *a))
				{
					push_min(a, b, first);
					/*if (*b != NULL)
					{
						if ((*b)->nb < list_dernier(*b))
							rb(b);
						else if ((*b)->nb < (*b)->next->nb && (*b)->nb > (*b)->)
							sb (*b);
						else if ((*b)->nb < (*b)->next->nb && (*b)->next->next->nb > (*b)->nb)
						{
							sb(*b);
							pa(a, b);
							sb(*b);
						}
					}*/
				}
				else
				{
					push_min(a, b, second);
					first = min_first(*a);
					push_min(a, b, first);
				}
				if (*b != NULL && (*b)->next != NULL && check_list_b(*b) == 0 && (*b)->nb < (*b)->next->nb && (*b)->nb > list_dernier(*b))
				{
					if ((*a)->next != NULL && (*a)->nb > (*a)->next->nb)
						ss(*a, *b);
					else
						sb(*b);
				}
				else if (*b != NULL && (*b)->next != NULL && check_list_b(*b) == 0 && (*b)->nb < list_dernier(*b)) 
				{
					rb(b);
				}
			}
			moyen(a, b);
		}
	}
}
