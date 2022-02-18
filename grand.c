/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grand.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaga <raaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:16:29 by raaga             #+#    #+#             */
/*   Updated: 2022/02/18 14:25:53 by raaga            ###   ########.fr       */
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



t_tab	check_chunk(t_list *a)
{
	int	min;
	t_tab	tab;
	int	i;
	int	j;

	tab.tab = malloc(sizeof(int) * (taille_list(a) + 1));
	tab.size = taille_list(a);
	if (!tab.tab)
	{
		exit(0);
	}
	i = 0;
	while (i < tab.size)
	{
		tab.tab[i] = a->nb;
		if (a->next == NULL)
			break ;
		a = a->next;
		i++; 
	}
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

void	create_chunk(int	*tab, t_list *a)
{	
	int	size;

	size = taille_list(a);
	size = size / 3;
	int	i;

	i = 0;
	while (i < size)
	{
		ft_printf("%d	", tab[i]);
		i++;
	}
}
