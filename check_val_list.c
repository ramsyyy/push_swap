/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_val_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaga <raaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:15:24 by raaga             #+#    #+#             */
/*   Updated: 2022/02/02 19:56:16 by raaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	taille_list(t_list *a)
{
	int	x;

	x = 1;
	while (a != NULL)
	{
		if (a->next == NULL)
			break ;
		a = a->next;
		x++;
	}
	return (x);
}

int	addition_list(t_list *a)
{
	int	x;

	x = 0;
	while (a != NULL)
	{
		x += a->nb;
		if (a->next == NULL)
			break ;
		a = a->next;
	}
	return (x);
}

int	moyen_list(t_list *a)
{
	int	x;
	int	y;
	int	z;

	x = taille_list(a);
	y = addition_list(a);
	z = y / x;
	return (z);
}

int	check_list(t_list *a, t_list *b)
{
	if (b != NULL)
		return (0);
	(void)b;
	if (a->prev != NULL)
		back_to_start(&a);
	while (a != NULL)
	{
		if (a->next == NULL)
			break ;
		if (a->nb > a->next->nb)
			return (0);
		a = a->next;
	}
	return (1);
}

int	check_list_a(t_list *a)
{
	if (a == NULL)
		return (1);
	if (a->prev != NULL)
		back_to_start(&a);
	while (a != NULL)
	{
		if (a->next == NULL)
			break ;
		if (a->nb > a->next->nb)
		{
			back_to_start(&a);
			return (0);
		}
		a = a->next;
	}
	back_to_start(&a);
	return (1);
}

int	check_list_b(t_list *a)
{
	if (a == NULL)
		return (1);
	if (a->prev != NULL)
		back_to_start(&a);
	while (a != NULL)
	{
		if (a->next == NULL)
			break ;
		if (a->nb < a->next->nb)
		{
			back_to_start(&a);
			return (0);
		}
		a = a->next;
	}
	back_to_start(&a);
	return (1);
}

int	list_dernier(t_list *a)
{
	int	tmp;

	go_to_end(&a);
	tmp = a->nb;
	back_to_start(&a);
	return (tmp);
}

/*
void	sup_moy(t_list **a, t_list **b, t_moy x)
{

}*/

void	algo(t_list **a, t_list **b)
{
	t_moy	x;

	x.taille = taille_list(*a);
	x.total = addition_list(*a);
	x.moy = moyen_list(*a);
	while (check_list(*a, *b) == 0)
	{
		while (check_list_a(*a) == 0)
		{
			if (*b != NULL)
			{
				if ((*b)->next != NULL)
				{
					if ((*b)->nb < (*b)->next->nb && (*a)->nb > (*a)->next->nb)
						ss(*a, *b);
					/*if ((*a)->nb > list_dernier(*a) && (*b)->nb < list_dernier(*b))
					{
						rrr(a, b);
					}*/
					if ((*a)->nb > x.moy && (*b)->nb > x.moy)
						rr(a, b);
				}
			}
			if (((*a)->nb > (*a)->next->nb && (*a)->next->nb > list_dernier(*a)) || ((*a)->nb < (*a)->next->nb && (*a)->nb < list_dernier(*a)) || ((*a)->nb > (*a)->next->nb && (*a)->nb < list_dernier(*a)))
				sa(*a);
			else if ((*a)->nb > x.moy )
				ra(a);
			else if ((*a)->nb > list_dernier(*a) && list_dernier(*a) <= x.moy)
				rra(a);
			else if ((*a)->nb < (*a)->next->nb && (*a)->nb < list_dernier(*a))
				pb(b, a);
			back_to_start(a);
			if (b != NULL)
				back_to_start(b);
		}

		if (check_list_b(*b) == 0)
		{
			if ((*b)->nb < (*b)->next->nb)
				sb(*b);
			else if ((*b)->nb < list_dernier(*b))
			{
				rrb(b);
				back_to_start(b);
			}

		}
		if (*b != NULL)
			pa(a, b);

	}
}