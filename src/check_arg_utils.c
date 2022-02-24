/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaga <raaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:25:29 by raaga             #+#    #+#             */
/*   Updated: 2022/02/24 15:04:37 by raaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	check_doublons_utils2(int argc, int *tab)
{
	int		i;
	int		q;

	i = 0;
	while (i < argc - 1)
	{
		q = i + 1;
		while (q < argc - 1)
		{
			if (tab[i] == tab[q])
			{
				free(tab);
				return (0);
			}
			q++;
		}
		i++;
	}
	return (1);
}

int	*transform_to_int(char **argv, int argc)
{
	int	*tab;
	int	i;

	i = 0;
	tab = malloc(sizeof(int) * (argc - 1));
	if (!tab)
		exit(0);
	while (i < argc - 1)
	{
		tab[i] = atoi(argv[i + 1]);
		i++;
	}
	return (tab);
}

int	check_doublons(int argc, char **argv)
{
	int		tmp2;
	int		i;
	char	**tmp;
	int		*tab;

	tmp2 = argc;
	if (argc == 2)
	{
		if (argv[1][0] == '\0')
			exit(0);
		tmp = argv;
		argv = list_atoi(tmp);
		argc = count_split(argv);
	}
	tab = transform_to_int(argv, argc);
	i = argc;
	ft_free_mod(argc, argv, tmp2);
	if (check_doublons_utils2(i, tab) == 0)
		return (0);
	free(tab);
	return (1);
}

int	check_int(int argc, char **argv)
{
	int		i;
	int		tmp2;
	char	**tmp;

	i = 1;
	tmp2 = argc;
	if (argc == 2)
	{
		tmp = argv;
		argv = list_atoi(tmp);
		argc = count_split(argv);
	}
	while (i < argc)
	{
		if ((ft_strcmp(argv[i], "2147483647") > 0
				&& ft_strlen(argv[i]) >= 10)
			|| (ft_strcmp(argv[i], "-2147483648") > 0
				&& ft_strlen(argv[i]) >= 11))
			return (0);
		i++;
	}
	ft_free_mod(argc, argv, tmp2);
	return (1);
}
