/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaga <raaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 13:12:23 by raaga             #+#    #+#             */
/*   Updated: 2022/01/28 17:48:00 by raaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
int	check_list(t_list *a, t_list *b)
{
	if (b != NULL)
		return (0);
	if (a->prev != NULL)
		back_to_start(&a);
	while (a->next != NULL || a->nb > a->next->nb)
	{

	}

}*/

int main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	(void)b;
	if (check_arg(argc, argv) == -1)
	{
		ft_printf("error\n");
		return (0);
	}
	b = NULL;
	a = list_init(argc, argv);


}	