/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaga <raaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 13:12:23 by raaga             #+#    #+#             */
/*   Updated: 2022/01/26 20:51:22 by raaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	if (check_arg(argc, argv) == -1)
	{
		ft_printf("error\n");
		return (0);
	}
	b = NULL;
	a = list_init(argc, argv);

	pb(&b,&a);
	pb(&b,&a);
	pb(&b,&a);
	pb(&b,&a);
	pb(&b,&a);


	//printf("%d\n", a->next->nb);
	display_list(a);
	ft_printf("\n");
	display_list(b);
	//sleep(15);
}	