/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaga <raaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:25:29 by raaga             #+#    #+#             */
/*   Updated: 2022/02/21 18:29:15 by raaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	check_doublons_utils(int argc, char **argv, int tmp)
{
	int		i;
	int		q;

	i = 1;
	while (i < argc)
	{
		q = i + 1;
		while (q < argc)
		{
			if (ft_strcmp(argv[i], argv[q]) == 0)
			{
				ft_free_mod(argc, argv, tmp);
				return (0);
			}
			q++;
		}
		i++;
	}
	return (1);
}

int	check_doublons(int argc, char **argv)
{
	int		tmp2;
	char	**tmp;

	tmp2 = argc;
	if (argc == 2)
	{
		tmp = argv;
		argv = list_atoi(tmp);
		argc = count_split(argv);
	}
	if (check_doublons_utils(argc, argv, tmp2) == 0)
		return (0);
	if (tmp2 == 2)
	{
		while (--argc >= 0)
			free(argv[argc]);
		free(argv);
	}
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
