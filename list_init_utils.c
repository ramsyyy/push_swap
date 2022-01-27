/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_init_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaga <raaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:13:23 by raaga             #+#    #+#             */
/*   Updated: 2022/01/26 20:46:49 by raaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	back_to_start(t_list **a)
{
	if (a == NULL)
	{
		if ((*a)->next != NULL)
			*a = (*a)->next;
		else if ((*a)->prev != NULL)
			*a = (*a)->prev;
		return ;
	}
	while (a != NULL)
	{
		if ((*a)->prev == NULL)
			break;
		*a = (*a)->prev;
	}
}

void	go_to_end(t_list **a)
{
	if (*a == NULL)
	{
		if ((*a)->prev != NULL)
			*a = (*a)->prev;
		else if ((*a)->next != NULL)
			*a = (*a)->next;
		return ;
	}
	while (*a != NULL)
	{
		if ((*a)->next == NULL)
			break;
		*a = (*a)->next;
	}
}