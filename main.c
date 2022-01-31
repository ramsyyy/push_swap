/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaga <raaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 13:12:23 by raaga             #+#    #+#             */
/*   Updated: 2022/01/31 22:48:51 by raaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_list(t_list *a, t_list *b)
{
	if (b != NULL)
		return (0);
	(void)b;
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

void	affiche_a(t_list *a)
{
	printf("%d\n", a->nb);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	(void)b;
	(void)a;
	if (check_arg(argc, argv) == -1)
	{
		ft_printf("error\n");
		return (0);
	}
	b = NULL;
	a = list_init(argc, argv);
	while (check_list(a, b) == 0)
	{
		while (check_list_a(a) == 0)
		{
			if (b != NULL)
			{
				if (b->next != NULL)
				{
					if (b->nb < b->next->nb && a->nb > a->next->nb)
						ss(a, b);
					if (a->nb > list_dernier(a) && b->nb < list_dernier(b))
					{
						rrr(a, b);
					}
				}		
			}
			if (a->nb > a->next->nb)
				sa(a);
			else if (a->nb > list_dernier(a))
				rra(a);
			else if (a->nb < a->next->nb && a->nb < list_dernier(a) && (check_list_a(a) == 0))
			{
				pb(&b, &a);
			}
			back_to_start(&a);
			if (b != NULL)
				back_to_start(&b);
		}
		if (check_list_b(b) == 0)
		{
			if (b->nb < b->next->nb)
				sb(b);
			else if (b->nb < list_dernier(b))
			{
				rrb(b);
				back_to_start(&b);
			}
		}
		if (b != NULL)
			pa(&a, &b);
	}
	//display_list(a);
}	
