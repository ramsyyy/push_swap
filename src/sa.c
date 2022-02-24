/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaga <raaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 13:00:43 by raaga             #+#    #+#             */
/*   Updated: 2022/02/23 13:27:26 by raaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rrr(t_list **a, t_list **b)
{
	ft_rra(a);
	ft_rra(b);
	ft_printf("rrr\n");
}

void	sasb(t_list *a)
{
	int	tmp;

	if (a->prev == NULL)
	{
		tmp = a->nb;
		a->nb = a->next->nb;
		a->next->nb = tmp;
	}
	back_to_start(&a);
}
