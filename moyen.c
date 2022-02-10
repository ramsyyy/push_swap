/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moyen.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramsy <ramsy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:41:03 by raaga             #+#    #+#             */
/*   Updated: 2022/02/10 03:08:42 by ramsy            ###   ########.fr       */
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

void	push_min_second(t_list **a, t_list **b, int min)
{
	int	tmp;
	if (*a == NULL)
		return ;
	if (min > taille_list(*a) / 2)
	{
		while (min <= taille_list(*a))
		{
			rra(a);
			min++;
		}
		if ((*a)->nb < (*b)->next->nb)
		{
			tmp = distance_place(*b, (*a)->nb) + 1;
			if (tmp == 1)
			{
				if ((*a)->nb < (*b)->nb && (*a)->nb > (*b)->next->nb)
				{
					pb(b, a);
					sb(*b);
				}
			}
			else if (distance_place(*b, (*a)->nb) <= taille_list(*b) / 2)
			{
				while ((*a)->nb < (*b)->nb)
					rb(b);
				//if ((*a)->nb > (*b)->nb)
					pb(b, a);
				while (tmp > 1)
				{
					rrb(b);
					tmp--;
				}
			}
			else if (distance_place(*b, (*a)->nb) > taille_list(*b) / 2)
			{
				while ((*a)->nb > (*b)->nb)
					rrb(b);
				//if ((*a)->nb > (*b)->nb)
					pb(b, a);
				while (tmp > 1)
				{
					rb(b);
					tmp--;
				}
			}
		}
	}
	else
	{
		while (min > 1)
		{
			ra(a);
			min--;
		}
		if ((*a)->nb < (*b)->next->nb)
		{
			tmp = distance_place(*b, (*a)->nb) + 1;
			if (tmp == 1)
			{
				if ((*a)->nb < (*b)->nb && (*a)->nb > (*b)->next->nb)
				{
					pb(b, a);
					sb(*b);
				}
			}
			else if (distance_place(*b, (*a)->nb) <= taille_list(*b) / 2)
			{
				while ((*a)->nb < (*b)->nb)
					rb(b);
				//if ((*a)->nb > (*b)->nb)
					pb(b, a);
				while (tmp > 1)
				{
					rrb(b);
					tmp--;
				}
			}
			else if (distance_place(*b, (*a)->nb) > taille_list(*b) / 2)
			{
				while ((*a)->nb > (*b)->nb)
					rrb(b);
				//if ((*a)->nb > (*b)->nb || (*a)->nb <list_dernier(*b))
					pb(b, a);
				while (tmp > 1)
				{
					rb(b);
					tmp--;
				}
			}
		}
	}
}

/*void	push_min(t_list **a, t_list **b, int min)
{
	int	tmp;
	if (*a == NULL)
		return ;
	if (min > taille_list(*a) / 2)
	{
		while (min <= taille_list(*a))
		{
			rra(a);
			min++;
		}
		if ((*a)->nb < nb_index(*b, min_first(*b)))
		{
			tmp = min_first(*b);
			if (tmp == taille_list(*b))
			{
				pb(b, a);
				rb(b);
			}
			if (min_first(*b) >= taille_list(*b) / 2)
			{
				while (tmp != taille_list(*b))
				{
					rrb(b);
					tmp++;
				}
				pb(b, a);
				tmp = nb_index(*b, min_first(*b));
				while (list_dernier(*b) != tmp)
					rb(b);
			}
			else
			{
				while (tmp != 1)
					rb(b);
				pb(b, a);
				tmp = nb_index(*b, min_first(*b));
				while (list_dernier(*b) != tmp)
					rrb(b);
			}
		}
		if ((*a)->nb < (*b)->next->nb)
		{
			tmp = distance_place(*b, (*a)->nb) + 1;
			if (tmp == 1)
			{
				if ((*a)->nb < (*b)->nb && (*a)->nb > (*b)->next->nb)
				{
					pb(b, a);
					sb(*b);
				}
			}
			else if (distance_place(*b, (*a)->nb) <= taille_list(*b) / 2)
			{
				while ((*a)->nb < (*b)->nb)
					rb(b);
				//if ((*a)->nb > (*b)->nb)
					pb(b, a);
				while (tmp > 1)
				{
					rrb(b);
					tmp--;
				}
			}
			else if (distance_place(*b, (*a)->nb) > taille_list(*b) / 2)
			{
				while ((*a)->nb > (*b)->nb)
					rrb(b);
				if ((*a)->nb > (*b)->nb)
					pb(b, a);
				while (tmp > 1)
				{
					rb(b);
					tmp--;
				}
			}
		}
	}
	else
	{
		while (min > 1)
		{
			ra(a);
			min--;
		}
		if ((*a)->nb < (*b)->next->nb)
		{
			tmp = distance_place(*b, (*a)->nb) + 1;
			if (tmp == 1)
			{
				if ((*a)->nb < (*b)->nb && (*a)->nb > (*b)->next->nb)
				{
					pb(b, a);
					sb(*b);
				}
			}
			else if (distance_place(*b, (*a)->nb) <= taille_list(*b) / 2)
			{
				while ((*a)->nb < (*b)->nb)
					rb(b);
				//if ((*a)->nb > (*b)->nb)
					pb(b, a);
				while (tmp > 1)
				{
					rrb(b);
					tmp--;
				}
			}
			else if (distance_place(*b, (*a)->nb) > taille_list(*b) / 2)
			{
				while ((*a)->nb > (*b)->nb)
					rrb(b);
				//if ((*a)->nb > (*b)->nb || (*a)->nb <list_dernier(*b))
					pb(b, a);
				while (tmp > 1)
				{
					rb(b);
					tmp--;
				}
			}
		}
	}
}*/

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
