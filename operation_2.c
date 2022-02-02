/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaga <raaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:13:04 by raaga             #+#    #+#             */
/*   Updated: 2022/02/02 16:31:53 by raaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **a)
{
	ft_ra(a);
	ft_printf("ra\n");
}

void	rb(t_list **b)
{
	ft_ra(b);
	ft_printf("rb\n");
}

void	rr(t_list **a, t_list **b)
{
	ft_ra(a);
	ft_ra(b);
	ft_printf("rr\n");
}

void	rra(t_list **a)
{
	ft_rra(a);
	ft_printf("rra\n");
}

void	rrb(t_list **b)
{
	ft_rra(b);
	ft_printf("rrb\n");
}

void	rrr(t_list **a, t_list **b)
{
	ft_rra(a);
	ft_rra(b);
	ft_printf("rrr\n");
}
