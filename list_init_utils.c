/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_init_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaga <raaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:13:23 by raaga             #+#    #+#             */
/*   Updated: 2022/02/16 16:07:11 by raaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	back_to_start(t_list **a)
{
	while (*a != NULL)
	{
		if ((*a)->prev == NULL)
			break ;
		*a = (*a)->prev;
	}
}

void	go_to_end(t_list **a)
{
	while (*a != NULL)
	{
		if ((*a)->next == NULL)
			break ;
		*a = (*a)->next;
	}
}

int	taille_list(t_list *a)
{
	int	x;

	x = 0;
	while (a != NULL)
	{	
		x++;
		if (a->next == NULL)
			break ;
		a = a->next;
	}
	return (x);
}
