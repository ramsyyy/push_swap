/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moyen.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaga <raaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:41:03 by raaga             #+#    #+#             */
/*   Updated: 2022/02/03 20:14:46 by raaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max(t_list *a)
{
	int	max;
	int	i;

	i = 0;
	max = 0;
	while (a != NULL)
	{
		if (a->next == NULL)
		{
			break ;
		}
		if (max < a->nb)
		{
			i++;
			max = a->nb;
		}
		a = a->next;
	}
	return (i);
}

void	moyen(t_list **a, t_list **b)
{
	int	i;
	while (check_list(*a, *b) == 0)
	{
		i = max(*a);
		if (i < taille_list(*a)/2)
		{
			while (i > 0)
			{
				ra(a);
			}
			pb(b, a);
		}
		display_list(*b);
	}
}