/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moyen.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaga <raaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:41:03 by raaga             #+#    #+#             */
/*   Updated: 2022/02/14 22:06:29 by raaga            ###   ########.fr       */
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
	tmp = a->nb;
	while (a != NULL)
	{
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
/*
int	max_first(t_list *a)
{
	int	tmp;
	int	i;
	int	pos;

	pos = 0;
	i = 1;
	tmp = a->nb;
	while (a != NULL)
	{
		if (tmp <= a->nb)
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
}*/

int	min_second(t_list *a)
{
	int min;
	int	tmp;
	int	i;
	int	pos;

	min = min_first(a);
	pos = 1;
	i = 1;
	if (min != 1)
		tmp = a->nb;
	else
		tmp = a->next->nb;
	while (a != NULL)
	{
		if (i == min)
		{
			i++;
			if (a->next == NULL)
				break ;
			a = a->next;
		}
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

int	mouv_sup(t_list *a, t_list *b)
{
	if (nb_index(a, min_mouv(a)) < b->nb)
	{
		int	tmp;

		if (nb_index(a, min_mouv(a))< nb_index(b, min_first(b)))
		{
			tmp = min_first(b);
			if (tmp > taille_list(b) / 2)
				if(tmp < taille_list(b))
					return (1);
		}
		else if (distance_place2(b, nb_index(a, min_mouv(a))) > taille_list(b) / 2)
			if (distance_place2(b, nb_index(a, min_mouv(a))) <= taille_list(b) - 1)
				return (1);
	}
	else
	{
		if (nb_index(a, min_mouv(a)) > nb_index(b, max_first(b)))
		{
			if (max_first(b) > taille_list(b) / 2)
				if (max_first(b) <= taille_list(b))
					return (1);
		}
		else if (nb_index(a, min_mouv(a)) > b->nb)
		{
			if (max_two(nb_index(a, min_mouv(a)), b) > taille_list(b) / 2)
				if (max_two(nb_index(a, min_mouv(a)), b) <= taille_list(b))
					return (1);
		}
	}
	return (0);
}

int	mouv_sup2(t_list *a, t_list *b)
{
	if (nb_index(a, min_mouv(a)) < b->nb)
	{
		int	tmp;

		if (nb_index(a, min_mouv(a)) < nb_index(b, min_first(b)))
		{
			tmp = min_first(b);
			if (tmp < taille_list(b) / 2)
				if(tmp > 1)
					return (1);
		}
		else if (distance_place2(b, nb_index(a,min_mouv(a))) < taille_list(b) / 2)
			if (distance_place2(b, (a)->nb) > 1)
				return (1);
	}
	else
	{
		if (nb_index(a, min_mouv(a)) > nb_index(b, max_first(b)))
		{
			if (max_first(b) < taille_list(b) / 2)
				if (max_first(b) > 1)
					return (1);
		}
		else if (nb_index(a, min_mouv(a)) > b->nb)
		{
			if (max_two(nb_index(a, min_mouv(a)), b) < taille_list(b) / 2)
				if (max_two(nb_index(a, min_mouv(a)), b) > 1)
					return (1);
		}
	}
	return (0);
}

void	push_min_second(t_list **a, t_list **b, int min)
{
	(void)b;
	if (min == 0 || min == 1)
		return ;
	if (min > taille_list(*a) / 2)
	{
		while (min <= taille_list(*a))
		{
			if (mouv_sup(*a, *b) == 1)
				rrr(a , b);
			else
				rra(a);
			min++;
		}
	}
	else
	{
		while (min > 1)
		{
			if (mouv_sup2(*a, *b) == 1)
				rr(a, b);
			else
				ra(a);
			min--;
		}
	}
}

int	distance_place_a(t_list *a, int	min)
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
	if (min > taille_list(*b) / 2)
	{
		while (min < taille_list(*b))
		{
			rrb(b);
			min++;
		}
		pb(b, a);
	}
	else
	{
		while (min >= 1)
		{
			rb(b);
			min--;
		}
		pb(b, a);
	}
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
			if (taille_list(*a) == 5)
			{
				push_min(a, b ,first);
			}
			else if (distance(first, *a) <= distance(second, *a))
			{
				push_min(a, b, first);
			}
			else
			{
				push_min(a, b, second);
				first = min_first(*a);
				push_min(a, b, first);
			}
			if (*b != NULL && (*b)->next != NULL && check_list_b(*b) == 0 && (*b)->nb < (*b)->next->nb && (*b)->nb > list_dernier(*b))
					sb(*b);
			else if (*b != NULL && (*b)->next != NULL && check_list_b(*b) == 0)
			{
				rb(b);
			}

		}
		//display_list(*b);
		petit(a, b);
		while (taille_list(*b) > 0)
		{
			pa(a, b);
			if ((*a)->nb > list_dernier(*a))
				ra(a);
		}
	}
}
