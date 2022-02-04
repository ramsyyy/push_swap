/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   petit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaga <raaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:40:12 by raaga             #+#    #+#             */
/*   Updated: 2022/02/04 20:14:17 by raaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	petit(t_list **a, t_list **b)
{
	(void)b;
	if (taille_list(*a) <= 3)
	{
		while (check_list_a(*a) == 0)
		{
			if (((*a)->nb > (*a)->next->nb && (*a)->next->nb > list_dernier(*a))
				|| ((*a)->nb < (*a)->next->nb && (*a)->nb < list_dernier(*a))
				|| ((*a)->nb > (*a)->next->nb && (*a)->nb < list_dernier(*a)))
				sa(*a);
			else if ((*a)->nb > list_dernier(*a) && (*a)->nb < (*a)->next->nb)
				rra(a);
			else if ((*a)->nb > list_dernier(*a))
				ra(a);
			if (check_list_a(*a) != 0)
				break ;
		}
	}
}
