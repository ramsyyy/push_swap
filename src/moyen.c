/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moyen.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaga <raaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:41:03 by raaga             #+#    #+#             */
/*   Updated: 2022/02/23 13:14:10 by raaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	distance_place_a(t_list *a, int min)
{
	int	i;

	i = 0;
	back_to_start(&a);
	if (min > taille_list(a) / 2)
	{
		while (min <= taille_list(a))
		{
			i++;
			min++;
		}
	}
	else
	{
		while (min >= 1)
		{
			i++;
			min--;
		}
	}
	return (i);
}

void	push_min(t_list **a, t_list **b, int min)
{
	if (min > taille_list(*a) / 2)
	{
		while (min <= taille_list(*a))
		{
			rra(a);
			min++;
		}
		if (check_list(*a, *b) == 0)
			pb(b, a);
	}
	else
	{
		while (min > 1)
		{
			ra(a);
			min--;
		}
		if (check_list(*a, *b) == 0)
			pb(b, a);
	}
}

void	moyen(t_list **a, t_list **b)
{
	if (check_list(*a, *b) == 0)
	{
		mediane(a, b);
		if (taille_list(*b) == 2)
		{
			pa(a, b);
			pa(a, b);
			if ((*a)->nb > (*a)->next->nb)
				sa(*a);
		}
		else
			pa(a, b);
	}
}
