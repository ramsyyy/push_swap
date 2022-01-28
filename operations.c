/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaga <raaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 22:14:01 by raaga             #+#    #+#             */
/*   Updated: 2022/01/28 22:23:15 by raaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list *a)
{
	ft_printf("sa\n");
	sasb(a);
}

void	sb(t_list *b)
{
	ft_printf("sb\n"),
	sasb(b);
}

void	ss(t_list *a, t_list *b)
{
	sasb(a);
	sasb(b);
}

void	pa(t_list *a, t_list *b)
{
	
}