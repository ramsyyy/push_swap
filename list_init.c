/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaga <raaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:45:07 by raaga             #+#    #+#             */
/*   Updated: 2022/01/21 17:31:31 by raaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*ft_lstnew(int nb)
{
	t_list *new;

	new = malloc(sizeof(t_list));
	new->nb = nb;
	return (new);
}

t_list	*list_init(int argc, char **argv)
{
	t_list	*elem;
	t_list	*tmp;
	int		n;
	int		i;

	i = 0;
	n = argc - 1;
	tmp = NULL;
	while (++i <= n)
	{
		elem = ft_lstnew(atoi(argv[i]));
		if (i == 1)
			elem->prev = NULL;
		if (i > 1)
		{
			elem->prev = tmp;
			elem->prev->next = elem;
		}
		tmp = elem;
		if (i != n)
		{
			elem = elem->next;
		}
		else
			elem->next = NULL;
	}
	return (elem);
}

void	*back_to_start(t_list *a)
{
	while (a != NULL)
	{
		if (a->prev == NULL)
			break;
		a = a->prev;
	}
	return (a);
}

void	*go_to_end(t_list *a)
{
	while (a != NULL)
	{
		if (a->next == NULL)
			break;
		a = a->next;
	}
	return (a);
}

void	display_list(t_list *a)
{
	if (a->prev == NULL)
	{
		while (a != NULL)
	{
		printf("%d\n", a->nb);
		if (a->next == NULL)
			break;
		a = a->next;
	}
	}
}