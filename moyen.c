/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moyen.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaga <raaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:41:03 by raaga             #+#    #+#             */
/*   Updated: 2022/02/18 13:14:24 by raaga            ###   ########.fr       */
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

void	push_min_second(t_list **a, int min)
{
	if (min == 0 || min == 1)
		return ;
	if (min > taille_list(*a) / 2)
	{
		while (min <= taille_list(*a))
		{
			rra(a);
			min++;
		}
	}
	else
	{
		while (min > 1)
		{
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
	if (min > taille_list(*a) / 2)
	{
		while (min <= taille_list(*a))
		{
			rra(a);
			
			min++;
		}
		
		pb(b, a);
		
	}
	else
	{
		while (min > 1)
		{
			ra(a);
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
		petit(a, b);
		while (taille_list(*b) > 0)
		{
			pa(a, b);
			if ((*a)->nb > list_dernier(*a))
				ra(a);
		}
	}
}
