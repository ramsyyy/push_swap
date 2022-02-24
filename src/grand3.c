/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grand3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaga <raaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:29:17 by raaga             #+#    #+#             */
/*   Updated: 2022/02/23 13:13:48 by raaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_min3_utils(int min, int i, t_list **a, t_list **b)
{
	while (min <= taille_list(*b) && taille_list(*b) > 1)
	{
		if (i >= taille_list(*a) / 2)
		{
			rrr(a, b);
			i++;
		}
		else
			rrb(b);
		min++;
	}
}

void	push_min3(t_list **b, t_list **a, int min)
{
	int	i;

	i = distance_place4(*a, nb_index(*b, min));
	if (min > taille_list(*b) / 2)
	{
		push_min3_utils(min, i, a, b);
	}
	else
	{
		while (min > 1)
		{
			if (i < taille_list(*a) / 2 && i > 0)
			{
				rr(a, b);
				i--;
			}
			else
				rb(b);
			min--;
		}
	}
}

void	rotate_max(t_list **a, int tmp)
{
	if (tmp != taille_list(*a))
	{
		if (tmp > taille_list(*a) / 2)
		{
			while (tmp < taille_list(*a))
			{
				rra(a);
				tmp++;
			}
		}
		else
		{
			while (tmp >= 1)
			{
				ra(a);
				tmp--;
			}
		}
	}
}

void	finish(t_list **a, int max)
{
	int	tmp;

	tmp = 1;
	back_to_start(a);
	while (max != (*a)->nb)
	{
		(*a) = (*a)->next;
		tmp++;
	}
	back_to_start(a);
	rotate_max(a, tmp);
}

void	grand3(t_list **a, t_list **b)
{
	int	tmp;
	int	max;

	if (check_list(*a, *b) == 0)
	{
		mediane(a, b);
		go_to_end(a);
		max = (*a)->nb;
		if (check_list_b(*b) == 0)
		{
			while (taille_list(*b) >= 1)
			{
				nb_mouv2(a, b);
				back_to_start(b);
				tmp = min_mouv(*b);
				if (taille_list(*b) > 1)
					push_min3(b, a, tmp);
				push_position(a, b);
			}
		}
		else
			while (taille_list(*b) >= 1)
				pa(a, b);
		finish(a, max);
	}
}
