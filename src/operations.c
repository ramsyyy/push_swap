/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaga <raaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 22:14:01 by raaga             #+#    #+#             */
/*   Updated: 2022/02/23 13:14:20 by raaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa(t_list *a)
{
	sasb(a);
	ft_printf("sa\n");
}

void	sb(t_list *b)
{
	sasb(b);
	ft_printf("sb\n");
}

void	ss(t_list *a, t_list *b)
{
	sasb(a);
	sasb(b);
	ft_printf("ss\n");
}

void	pa(t_list **a, t_list **b)
{
	ft_pb(a, b);
	ft_printf("pa\n");
}

void	pb(t_list **b, t_list **a)
{
	ft_pb(b, a);
	ft_printf("pb\n");
}
