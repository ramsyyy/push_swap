/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaga <raaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:45:07 by raaga             #+#    #+#             */
/*   Updated: 2022/02/18 16:40:19 by raaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int nb)
{
	t_list *new;

	new = malloc(sizeof(t_list));
	new->nb = nb;
	new->mouv = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

char	**list_atoi(char **argv)
{
	char	**split;

	split = ft_split_mod(argv[1], ' ', argv[0]);
	return (split);
}

t_list	*init(int	argc, char **argv)
{
	t_list	*elem;
	t_list	*tmp;
	int		i;
	int		n;

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
			elem = elem->next;
		else
			elem->next = NULL;
	}
	return (elem);
}

int	count_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

t_list	*list_init(int argc, char **argv)
{
	t_list	*elem;
	char	**tmp;
	int		tmp2;

	tmp2 = argc;
	if (argc == 2)
	{
		tmp = argv;
		argv = list_atoi(tmp);
		argc = count_split(argv);
	}
	elem = init(argc, argv);
	if (tmp2 == 2)
	{
		while (argc >= 0)
		{
			free(argv[argc]);
			argc--;
		}
		free(argv);
	}
	back_to_start(&elem);
	return (elem);
}

void	display_list(t_list *a)
{
	if (a == NULL)
		return ;
	if (a->prev == NULL)
	{
		while (a != NULL)
		{
			ft_printf("%d\n", a->nb);
			if (a->next == NULL)
				break ;
			a = a->next;
		}
		return ;
	}
	else
	{
		back_to_start(&a);
		display_list(a);
	}
}
