/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaga <raaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 13:12:23 by raaga             #+#    #+#             */
/*   Updated: 2022/02/21 18:23:33 by raaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_mod(int argc, char **argv, int tmp)
{
	if (tmp == 2)
	{
		while (--argc >= 0)
			free(argv[argc]);
		free(argv);
	}
}

void	ft_free_lst(t_list **a)
{
	int		size;
	t_list	*tmp;

	size = taille_list(*a);
	while (size > 0)
	{
		tmp = (*a);
		(*a) = (*a)->next;
		free(tmp);
		size--;
	}
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	if (argc == 1)
		return (0);
	if (check_arg(argc, argv) == -1)
	{
		ft_printf("error\n");
		return (0);
	}
	b = NULL;
	a = list_init(argc, argv);
	algo(&a, &b);
	back_to_start(&a);
	ft_free_lst(&a);
}
