/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaga <raaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:07:04 by raaga             #+#    #+#             */
/*   Updated: 2022/02/21 18:26:39 by raaga            ###   ########.fr       */
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

	i = -1;
	nb = 0;
	if (!str || ft_strlen(str) == 0)
		return (0);
	while (str[++i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			nb++;
		else if (str[i] == '-')
		{
			if (!if_neg(str, i))
				return (0);
		}
		else if (str[i] != ' ' && str[i] != '-')
			return (0);
	}
	return (nb);
}

int	check_arg(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc <= 1)
		return (-1);
	if (check_doublons(argc, argv) == 0 || check_int(argc, argv) == 0)
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
