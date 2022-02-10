/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grand.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaga <raaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:16:29 by raaga             #+#    #+#             */
/*   Updated: 2022/02/10 20:51:02 by raaga            ###   ########.fr       */
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

int	nb_index(t_list *a, int index)
{
	int	nb;

	while (index > 0)
	{
		nb = a->nb;
		if (a->next != NULL && a != NULL)
		{
			a = a->next;
			index--;
		}
		else 
			break ;
		
	}
	return (nb);
}

int	verif_b(int nb, t_list *b)
{
	int	i;

	i = 0;
	while (nb < b->nb && b != NULL)
	{
		i++;
		if (b->next != NULL)
			b = b->next;
		else 
			break ;
	}
	return (i);
}



int	 *check_chunk(t_list *a)
{
	int	min;
	int	*tab;
	int	size;
	int	i;
	int	j;
	
//	min = min_first(a);
//	max = max_first(a);
	tab = malloc(sizeof(int) * (taille_list(a) + 1));
	if (!tab)
	{
		return NULL;
	}
	i = 0;
	size = taille_list(a);
	while (i < size)
	{
		tab[i] = a->nb;
		if (a->next == NULL)
			break ;
		a = a->next;
		i++; 
	}
	i = 0;
	while (i < size)
	{
		j = i;
		while (j < size)
		{
			if (tab[j] < tab[i])
			{
				min = tab[j];
				tab[j] = tab[i];
				tab[i] = min;
			}
			j++;
		}
		i++;
	}
	return (tab);
}

void	create_chunk(int	*tab, t_list *a)
{	
	int	size;

	size = taille_list(a);
	size = size / 5;
	int	i;

	i = 0;
	while (i < size)
	{
		ft_printf("%d", tab[i]);
		i++;
	}
}

void	grand(t_list **a, t_list **b)
{
	int	first;
	int	second;
	int	i;

	while (check_list(*a, *b) == 0)
	{
		if (check_list_a(*a) == 0)
		{
			while (taille_list(*a) > 5)
			{
				first = min_first(*a);
				second = min_second(*a);				
				if (distance(first, *a) <= distance(second, *a) || taille_list(*a) - 1 == 5)
				{
					if (*b != NULL && (*b)->next != NULL)
					{
						if (nb_index(*a, first) < (*b)->nb)
						{
							while (verif_b(nb_index(*a, first), *b) != 0)
							{
								if (verif_b(nb_index(*a, first), *b) == taille_list(*b))
									break ;
								if (first <= (taille_list(*a) / 2) && distance(first, *a) > 1)
								{
									rr(a, b);
									first--;
								}
								else
									rb(b);	
							}
						}
					}
					push_min(a, b, first);
					first = min_first(*a);
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
							rrb(b);
					}
				}
				else
				{
					push_min(a, b, second);
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
