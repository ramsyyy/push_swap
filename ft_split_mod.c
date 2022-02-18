/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_mod.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaga <raaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:32:27 by raaga             #+#    #+#             */
/*   Updated: 2022/02/18 16:23:00 by raaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_free(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static int	count_words(char const *s, char c)
{
	int	compteur;
	int	i;

	compteur = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			compteur++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (compteur);
}

static char	*ftt_strdup(char **tab, char const *s, char c)
{
	int		i;
	char	*dest;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	dest = (char *)malloc(sizeof(char) * (i + 1));
	if (!dest)
		ft_free(tab);
	i = 0;
	while (s[i] != c && s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split_mod(char const *s, char c, char *str)
{
	char	**tab;
	int		i;
	int		compteur;

	i = 1;
	if (!s)
		return (NULL);
	compteur = count_words(s, c);
	tab = (char **)malloc(sizeof(char *) * (compteur + 2));
	if (!tab)
	{
		ft_free(tab);
		return (NULL);
	}
	tab[0] = ftt_strdup(tab, str, c);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			tab[i] = ftt_strdup(tab, s, c);
			i++;
			while (*s != c && *s)
				s++;
		}
	}
	tab[i] = 0;
	return (tab);
}
