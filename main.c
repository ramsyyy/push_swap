/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaga <raaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 13:12:23 by raaga             #+#    #+#             */
/*   Updated: 2022/01/24 17:32:36 by raaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_list	*ft_lstnew(int nb)
{
	t_list *new;

	new = malloc(sizeof(t_list));
	new->nb = nb;
	return (new);
}

int main(int argc, char **argv)
{
	printf("%d\n", check_arg(argc, argv));
}