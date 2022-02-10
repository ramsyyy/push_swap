/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grand2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramsy <ramsy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:25:18 by raaga             #+#    #+#             */
/*   Updated: 2022/02/10 11:51:39 by ramsy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int distance_place(t_list *b, int nb)
{
	int	i;

	i = 0;
	if (b == NULL)
		return (0);
	while (b != NULL && nb < b->nb)
	{
		if (nb < b->nb)
			i++;
		else 
			return (i);
		if (b->next != NULL)
		{
			b = b->next;
		}
		else
			break ;
	}
	return (i);
}

void    grand2(t_list **a, t_list **b)
{
	int	first;
	int	second;
	int	i;
	int	tmp;

	while (check_list(*a, *b) == 0)
	{
		while (check_list_a(*a) == 0)
		{
			while (taille_list(*a) > 0)
			{
				if (taille_list(*a) > 2)
				{
					first = min_first(*a);
					second = min_second(*a);
				}
				/*if (distance(first, *a) > (distance_place(*b, (*a)->nb) * 2) && distance(second, *a) >= (distance_place(*b, (*a)->nb) * 2))
				{*/
					
					if (((*b == NULL || (*a)->nb > (*b)->nb) || ((*a)->nb < list_dernier(*b) && distance_place(*b, (*a)->nb) <= 1)))
					{
						pb(b, a);
						if ((*b)->nb < list_dernier(*b))
							rb(b);
					}
					else if (taille_list(*b) >= 1)
					{
						if ((*a)->nb < (*b)->nb)
						{
							if ((*a)->nb < nb_index(*b, min_first(*b)))
							{
								tmp = min_first(*b);
								if (tmp == taille_list(*b))
								{
									pb(b, a);
									rb(b);
								}
								else if (min_first(*b) >= taille_list(*b) / 2)
								{
									while (tmp <= taille_list(*b))
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
							else if (distance_place(*b, (*a)->nb) == 1)
							{
								if ((*a)->nb < (*b)->nb && (*a)->nb > (*b)->next->nb)
								{
									pb(b, a);
									sb(*b);
								}
							}
							else if (distance_place(*b, (*a)->nb) <= taille_list(*b) / 2)
							{
								tmp = distance_place(*b, (*a)->nb);
								i = tmp;
								while (tmp >= 1)
								{
									rb(b);
									tmp--;
								}
								pb(b, a);
								while (i >= 1)
								{
									rrb(b);
									i--;
								}
							}
							else if (distance_place(*b, (*a)->nb) > taille_list(*b) / 2)
							{
								tmp = distance_place(*b, (*a)->nb);
								i = tmp;
								while (tmp <= taille_list(*b) - 1)
								{
									rrb(b);
									tmp++;
								}
								pb(b, a);
								while (i <= taille_list(*b) - 1)
								{
									rb(b);
									i++;
								}
								
							}
						}
					}
				
			}
			while (*b != NULL)
				pa(a, b);
			
		}
		//display_list(*b);
		
	}
}
