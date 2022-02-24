/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grand_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaga <raaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:25:18 by raaga             #+#    #+#             */
/*   Updated: 2022/02/23 13:15:52 by raaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	min_mouv(t_list *a)
{
	int	i;
	int	tmp;
	int	pos;

	back_to_start(&a);
	i = a->mouv;
	tmp = 1;
	pos = 1;
	while (a != NULL)
	{
		if (i > a->mouv)
		{
			i = a->mouv;
			pos = tmp;
		}
		if (a->next == NULL)
			break ;
		else
		{
			a = a->next;
			tmp++;
		}	
	}
	return (pos);
}

int	distance_place3(t_list *b, int nb)
{
	int	i;

	i = 0;
	back_to_start(&b);
	if (b == NULL)
		return (0);
	while (b != NULL && nb != b->nb)
	{
		b = b->next;
		i++;
	}
	back_to_start(&b);
	i = distance_place_a(b, i);
	return (i);
}

int	distance_place4(t_list *a, int nb)
{
	int		i;
	int		j;
	t_tab	tab;

	i = 0;
	back_to_start(&a);
	tab = check_chunk(a);
	if (a == NULL)
		return (0);
	while (nb > tab.tab[i] && i < tab.size)
		i++;
	j = 0;
	while (a->nb != tab.tab[i])
	{
		a = a->next;
		j++;
	}
	back_to_start(&a);
	free(tab.tab);
	if (j > taille_list(a) / 2)
		return (taille_list(a) - j);
	else
		return (j);
}

int	distance_place5(t_list *a, int nb)
{
	int		i;
	int		j;
	t_tab	tab;

	i = 0;
	back_to_start(&a);
	tab = check_chunk(a);
	if (a == NULL)
		return (0);
	while (nb > tab.tab[i] && i < tab.size)
		i++;
	j = 0;
	while (a->nb != tab.tab[i])
	{
		a = a->next;
		j++;
	}
	free(tab.tab);
	back_to_start(&a);
	return (j);
}

void	nb_mouv2(t_list **a, t_list **b)
{
	int	tmp;
	int	size;

	tmp = 0;
	size = taille_list(*b);
	while (tmp < size)
	{
		(*b)->mouv = distance_place3(*b, (*b)->nb)
			+ distance_place4(*a, (*b)->nb);
		if ((*b)->next == NULL)
			break ;
		*b = (*b)->next;
		tmp++;
	}
	back_to_start(b);
}
