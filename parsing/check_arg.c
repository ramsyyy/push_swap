/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaga <raaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:07:04 by raaga             #+#    #+#             */
/*   Updated: 2022/02/18 21:06:11 by raaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	if_neg(char *str, int i)
{
	int	tmp;

	if (i > 0)
	{
		tmp = i - 1;
		if (str[tmp] == ' ' && ft_isdigit(str[i + 1]))
				return (1);
	}
	else
	{
		if (ft_isdigit(str[i + 1]))
			return (1);
	}
	return (0);
}

static int	check_numbers(char *str)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	if (!str || ft_strlen(str) == 0)
		return (0);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			i++;
			nb++;
		}
		else if (str[i] == ' ')
			i++;
		else if (str[i + 1] == ' ')
				i++;
		else if (str[i] == '-')
		{
			if (!if_neg(str, i))
				return (0);
			i++;
		}
		else
			return (0);
	}
	return (nb);
}

int	check_doublons(int argc, char **argv)
{
	int		i;
	int		q;
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
		q = i + 1;
		while (q < argc)
		{
			if ((ft_strcmp(argv[i], "2147483647") > 0
					&& ft_strlen(argv[i]) >= 10)
				|| (ft_strcmp(argv[i], "-2147483648") > 0
					&& ft_strlen(argv[i]) >= 11))
				return (0);
			if (ft_strcmp(argv[i], argv[q]) == 0) // CEST ICI AUE TA FOUTU TA MERDE 
			{
				if (argc == 2)
				{
					while (argc >= 0)
					{
						free(argv[argc]);
						argc--;
					}
					free(argv);
				}
				return (0);
			}
			q++;
		}
		i++;
	}
	if (tmp2 == 2)
	{
		while (argc >= 0)
		{
			free(argv[argc]);
			argc--;
		}
		free(argv);
	}
	return (1);
}

int	check_arg(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc <= 1)
		return (-1);
	if (check_doublons(argc, argv) == 0)
		return (-1);
	if (argc == 2)
	{
		if (check_numbers(argv[1]))
			return (1);
		else
			return (-1);
	}
	else
	{
		while (i < argc)
		{
			if (check_numbers(argv[i]))
				i++;
			else
				return (-1);
		}
		return (1);
	}
}
