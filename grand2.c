/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grand2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaga <raaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:25:18 by raaga             #+#    #+#             */
/*   Updated: 2022/02/14 21:47:51 by raaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int distance_place(t_list *b, int nb)
{
	int	i;

	i = 0;
	back_to_start(&b);
	if (b == NULL)
		return (0);
	while (b != NULL && nb < b->nb)
	{
		if (nb < b->nb)
			i++;
		else
			return (i);
		if (b->next != NULL)
		{
			b = b->next;
		}
		else
			break ;
	}
	back_to_start(&b);
	i = distance_place_a(b, i);
	return (i);
}

int distance_place2(t_list *b, int nb)
{
	int	i;

	i = 0;
	back_to_start(&b);
	if (b == NULL)
		return (0);
	while (b != NULL && nb < b->nb)
	{
		if (nb < b->nb)
			i++;
		else
			return (i);
		if (b->next != NULL)
		{
			b = b->next;
		}
		else
			break ;
	}
	return (i);
}

int	min_mouv(t_list *a)
{
	int	i;
	int	tmp;
	int	pos;

	back_to_start(&a);
	i = a->mouv;
	tmp = 1;
	pos = 1;
	while (a != NULL)
	{
		if (i > a->mouv)
		{
			i = a->mouv;
			pos = tmp;
		}
		if (a->next == NULL)
			break ;
		else
		{
			a = a->next;
			tmp++;
		}
	}
	return (pos);
}

int	max_first(t_list *a)
{
	int	tmp;
	int	i;
	int	pos;

	pos = 1;
	i = 1;
	tmp = a->nb;
	while (a != NULL)
	{
		if (tmp < a->nb)
		{
			pos = i;
			tmp = a->nb;
		}
		if (a->next == NULL)
			break ;
		a = a->next;
		i++;
	}
	return (pos);
}

int	min_two(int nb, t_list *b)
{
	int i;
	int	pos;

	i = 1;
	pos = 1;
	while (b != NULL)
	{
		while (taille_list(b) >= 1)
		{
			if (b->next == NULL)
			{
				if (nb > b->nb)
					pos = i;
				return (pos);
				break ;
			}
			else
			{
				if (nb > b->nb)
				{
					pos = i;
					while (nb > b->nb)
					{
						if (b->next == NULL)
							break ;
						b = b->next;
						pos = i;
						i++;
					}
					return (pos);

				}
				else
				{
					b = b->next;
					i++;
				}
			}
		}
	}
	return (pos);
}

int	max_two(int nb, t_list *b)
{
	int i;
	int	pos;

	i = 1;
	pos = 1;
	while (b != NULL)
	{
		while (taille_list(b) >= 1)
		{
			if (b->next == NULL)
			{
				if (nb < b->nb)
					pos = i;
				return (pos);
			}
			else
			{
				if (nb < b->nb)
				{
					pos = i;
					while (nb < b->nb)
					{
						if (b->next == NULL)
						{
							if (nb < b->nb)
								pos = i;
							return (pos);
						}
						b = b->next;
						pos = i;
						i++;
					}
					return (pos);

				}
				else
				{
					b = b->next;
					i++;
				}
			}
		}
	}
	return (pos);
}

int	nb_search(t_tab tab, int nb)
{
	int i;

	i = tab.size - 1;
	while (i > tab.size - 4)
	{
		if (nb == tab.tab[i])
			return (1);
		else
			i--;
	}
	return (0);
}

void	nb_mouv(t_list **a, t_list **b, t_tab tab)
{
	int	tmp;
	int	size;

	tmp = 0;
	size = taille_list(*a);
	while (tmp < size)
	{
		if (nb_search(tab, (*a)->nb) == 0)
			(*a)->mouv = distance_place_a(*a, tmp) + distance_place(*b, (*a)->nb);
		else
			(*a)->mouv = 3000000;
		if ((*a)->next == NULL)
			break ;
		*a = (*a)->next;
		tmp++;
	}
}

void    grand2(t_list **a, t_list **b)
{
	int	tmp;
	t_tab tab;

	tab = check_chunk(*a);
	//ft_printf("QWEQWEQWEQW %d\n", nb_search(tab, (*a)->nb));
	if (check_list(*a, *b) == 0)
	{
		if(check_list_a(*a) == 0)
		{
			while (taille_list(*a) > 3)
			{
				if (taille_list(*b) < 2)
				{
					if (nb_search(tab, (*a)->nb) == 0)
					{
						pb(b, a);
					}
					else
					{
						while (nb_search(tab, (*a)->nb) == 1)
						{
							ra(a);
						}
						pb(b, a);
					}
					if ((*b)->next != NULL && (*b)->nb < (*b)->next->nb)
						sb(*b);
				}
				else
				{
					if (*a == NULL)
						break ;
					nb_mouv(a, b, tab);
					back_to_start(a);
					tmp = min_mouv(*a);
					push_min_second(a, b, tmp);
					if (*a != NULL && (*a)->nb < (*b)->nb)
					{
						if ((*a)->nb < nb_index(*b, min_first(*b)))
						{
							tmp = min_first(*b);
							if (tmp == taille_list(*b))
							{
								pb(b, a);
								rb(b);
							}
							else
								push_min(a, b, tmp);
						}
						else if ((*a)->nb < (*b)->nb && (*a)->nb > (*b)->next->nb)
						{
							pb(b, a);
							sb(*b);
						}
						else if (distance_place2(*b, (*a)->nb) <= taille_list(*b) / 2)
						{
							tmp = distance_place2(*b, (*a)->nb);
							while (tmp >= 1)
							{
								rb(b);
								tmp--;
							}
							pb(b, a);
						}
						else if (distance_place2(*b, (*a)->nb) > taille_list(*b) / 2)
						{
							tmp = distance_place2(*b, (*a)->nb);
							while (tmp <= taille_list(*b) - 1)
							{
								rrb(b);
								tmp++;
							}
							pb(b, a);
						}
					}
					else
					{
						if ((*a)->nb > nb_index(*b, max_first(*b)))
						{
							tmp = max_first(*b);
							if (tmp == taille_list(*b))
							{
								rrb(b);
								pb(b, a);
							}
							else if (max_first(*b) > taille_list(*b) / 2)
							{
								while (tmp <= taille_list(*b))
								{
									rrb(b);
									tmp++;
								}
								pb(b, a);
							}
							else
							{
								while (tmp != 1)
								{
									rb(b);
									tmp--;
								}
								pb(b, a);
							}
						}
						else if ((*a)->nb > (*b)->nb)
						{
							tmp = max_two((*a)->nb, *b);
							push_min(a, b, tmp);
						}
						else
							pb(b, a);
					}
				}
			}
			tmp = min_first(*b);
			if (nb_index(*b, tmp) != list_dernier(*b))
			{
				if (tmp > taille_list(*b) / 2)
				{
					while (tmp < taille_list(*b))
					{
						rrb(b);
						tmp++;
					}
				}
				else
				{
					while (tmp >= 1)
					{
						rb(b);
						tmp--;
					}
				}
			}
			moyen(a, b);
		}
	}
}


