/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grand.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaga <raaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:16:29 by raaga             #+#    #+#             */
/*   Updated: 2022/02/23 13:13:34 by raaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

static t_tab	sort_in_tab(t_tab tab)
{
	int	i;
	int	j;
	int	min;

	i = 0;
	while (i < tab.size)
	{
		j = i;
		while (j < tab.size)
		{
			if (tab.tab[j] < tab.tab[i])
			{
				min = tab.tab[j];
				tab.tab[j] = tab.tab[i];
				tab.tab[i] = min;
			}
			j++;
		}
		i++;
	}
	return (tab);
}

t_tab	check_chunk(t_list *a)
{
	int		i;
	t_tab	tab;

	tab.tab = malloc(sizeof(int) * (taille_list(a) + 1));
	tab.size = taille_list(a);
	if (!tab.tab)
		exit(0);
	i = 0;
	while (i < tab.size)
	{
		tab.tab[i] = a->nb;
		if (a->next == NULL)
			break ;
		a = a->next;
		i++;
	}
	tab = sort_in_tab(tab);
	return (tab);
}

void	mediane(t_list **a, t_list **b)
{
	int		mediane;
	int		max;
	int		i;
	t_tab	tab;

	tab = check_chunk(*a);
	max = tab.size - 1;
	mediane = tab.tab[tab.size / 2];
	i = 0;
	while (i < tab.size)
		i++;
	while (taille_list(*a) > 3)
	{
		while ((*a)->nb == tab.tab[max]
			|| (*a)->nb == tab.tab[max - 1] || (*a)->nb == tab.tab[max - 2])
			ra(a);
		pb(b, a);
		if ((*b)->nb < mediane && taille_list(*b) > 1)
			rb(b);
	}
	free(tab.tab);
	petit(a, b);
}

void	push_position(t_list **a, t_list **b)
{
	int	i;

	i = distance_place5(*a, (*b)->nb);
	if (i > taille_list(*a) / 2)
	{
		while (i < taille_list(*a))
		{
			rra(a);
			i++;
		}
		pa(a, b);
	}
	else
	{
		while (i >= 1)
		{
			ra(a);
			i--;
		}
		pa(a, b);
	}
}
