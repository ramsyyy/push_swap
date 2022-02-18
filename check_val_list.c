/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_val_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaga <raaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:15:24 by raaga             #+#    #+#             */
/*   Updated: 2022/02/18 20:21:22 by raaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (a == NULL)
		return (0);
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

void	algo(t_list **a, t_list **b)
{
	t_moy	x;

	x.taille = taille_list(*a);
	x.total = addition_list(*a);
	x.moy = moyen_list(*a);
	if (x.taille <= 3)
		petit(a, b);
	else if (x.taille <= 5)
		moyen(a, b);
	else if (x.taille >= 6)
		grand3(a, b);
}