/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_val_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaga <raaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:15:24 by raaga             #+#    #+#             */
/*   Updated: 2022/02/23 13:15:42 by raaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
	int	size;

	size = taille_list(*a);
	if (size <= 3)
		petit(a, b);
	else if (size <= 5)
		moyen(a, b);
	else if (size >= 6)
		grand3(a, b);
}
