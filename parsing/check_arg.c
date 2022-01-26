/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaga <raaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:07:04 by raaga             #+#    #+#             */
/*   Updated: 2022/01/26 14:30:17 by raaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * @brief verifier le caractere precedant le caractere '-' et le suivant
 *
 * @param str la string
 * @param i l'emplacement du caractere negative
 * @return int
 */

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

/**
 * @brief
 * verifier qu'il n'y a que des chiffre dans la string envoyé.
 * @param str string dans l'argument du main.
 * @return int retourne 1 ou -1.
 */

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

/**
 * @brief check les argument passer en parametre
 *
 * @param argc
 * @param argv
 * @return int
 */

int	check_arg(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc <= 1)
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