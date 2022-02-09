/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grand2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaga <raaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:25:18 by raaga             #+#    #+#             */
/*   Updated: 2022/02/09 22:07:57 by raaga            ###   ########.fr       */
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
		if (nb > b->nb)
		{
			return (i);
		}
		if (b->next != NULL)
		{
			b = b->next;
			i++;
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
	//int	i;
	int	tmp;

	while (check_list(*a, *b) == 0)
	{
		while (check_list_a(*a) == 0)
		{
			while (taille_list(*a) > 1)
			{
				first = min_first(*a);
				second = min_second(*a);
				if (distance(first, *a) > (distance_place(*b, (*a)->nb) * 2) && distance(second, *a) >= (distance_place(*b, (*a)->nb) * 2))
				{
					if (((*b == NULL || (*a)->nb > (*b)->nb) || (*a)->nb < list_dernier(*b)) && distance_place(*b, (*a)->nb) <= 1)
					{
						pb(b, a);
						if ((*b)->nb < list_dernier(*b))
							rb(b);
					}
					else if (taille_list(*b) >= 2)
					{
						if ((*a)->nb < (*b)->nb)
						{
							if ((*a)->nb < nb_index(*b, min_first(*b)))
							{
								tmp = min_first(*b);
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
							
							tmp = distance_place(*b, (*a)->nb);
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
								{
									rb(b);
								}
								if ((*a)->nb > (*b)->nb)
									pb(b, a);
								while (tmp >= 1)
								{
									rrb(b);
									tmp--;
								}
							}
							else if (distance_place(*b, (*a)->nb) > taille_list(*b) / 2)
							{
								while ((*a)->nb > (*b)->nb)
								{
									rrb(b);
								}
								if ((*a)->nb > (*b)->nb)
									pb(b, a);
								while (tmp >= 1)
								{
									rb(b);
									tmp--;
								}
								
							}
						}
					}	
				}					
				else if (distance(first, *a) <= distance(second, *a) || taille_list(*a) - 1 == 5)
				{
					/*if (*b != NULL && (*b)->next != NULL)
					{
						if (nb_index(*a, first) < (*b)->nb)
						{
							while (verif_b(nb_index(*a, first), *b) != 0)
							{
								if (verif_b(nb_index(*a, first), *b) == taille_list(*b))
									break ;
								tmp = first;
								if (first <= (taille_list(*a) / 2) && distance(first, *a) > 1)
								{
									rr(a, b);
									first--;
								}
								else
									rb(b);	
							}
						}
					}*/
					push_min(a, b, first);
					/*first = min_first(*a);
					second = min_second(*a);
					if (distance(first, *a) <= distance(second, *a))
						i = 1;
					else 
						i = 2;
					while (*b != NULL && (*b)->next != NULL && check_list_b(*b) == 0 && (*b)->nb < list_dernier(*b))
					{
						if (i == 1 && first > (taille_list(*a) / 2) && first < taille_list(*a))
						{
							rrr(a, b);
							first++;
						}
						else if (i == 2 && second > (taille_list(*a) / 2) && second < taille_list(*a))
						{
							rrr(a, b);
							second++;
						}
						else
						{
							//display_list(*a);
							rrb(b);
						}
					}*/
				}
				else
				{
					push_min_second(a, b, second);
				}

			/*
				if (*b != NULL && (*b)->next != NULL && check_list_b(*b) == 0 && (*b)->nb < (*b)->next->nb && (*b)->nb > list_dernier(*b))
				{
					if ((*a)->next != NULL && (*a)->nb > (*a)->next->nb)
					{
						ss(*a, *b);
					}
					else
						sb(*b);
				}
				else if (*b != NULL && (*b)->next != NULL && check_list_b(*b) == 0 && (*b)->nb < list_dernier(*b)) 
				{
					rb(b);
				}*/
			}
			//while (*b != NULL)
			//	pa(a, b);
		}
		display_list(*b);
	}
}