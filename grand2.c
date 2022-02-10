/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grand2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaga <raaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:25:18 by raaga             #+#    #+#             */
/*   Updated: 2022/02/10 19:18:18 by raaga            ###   ########.fr       */
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


/*
void    grand2(t_list **a, t_list **b)
{
	int	first;
	int	second;
	int	tmp;

	while (check_list(*a, *b) == 0)
	{
		while (check_list_a(*a) == 0)
		{
			while (taille_list(*a) > 0)
			{		
					if (((*b == NULL || (*a)->nb > (*b)->nb) || ((*a)->nb < list_dernier(*b) && distance_place(*b, (*a)->nb) <= 1)))
					{
						pb(b, a);
						if ((*b)->nb < list_dernier(*b))
							rb(b);
					}
					else if (taille_list(*b) >= 1)
					{
						if ((*a)->nb < (*b)->nb)
						{
							if ((*a)->nb < nb_index(*b, min_first(*b)))
							{
								tmp = min_first(*b);
								if (tmp == taille_list(*b))
								{
									pb(b, a);
									rb(b);
								}
								else if (min_first(*b) >= taille_list(*b) / 2)
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
										rb(b);
									pb(b, a);

								}
							}
							else if (distance_place(*b, (*a)->nb) == 1)
							{
								if ((*a)->nb < (*b)->nb && (*a)->nb > (*b)->next->nb)
								{
									pb(b, a);
									sb(*b);
								}
							}
							else if (distance_place(*b, (*a)->nb) <= taille_list(*b) / 2)
							{
								tmp = distance_place(*b, (*a)->nb);
								while (tmp >= 1)
								{
									rb(b);
									tmp--;
								}
								pb(b, a);
							}
							else if (distance_place(*b, (*a)->nb) > taille_list(*b) / 2)
							{
								tmp = distance_place(*b, (*a)->nb);
								while (tmp <= taille_list(*b) - 1)
								{
									rrb(b);
									tmp++;
								}
								pb(b, a);
								
							}
						}
					}
				
			}
			while (*b != NULL)
				pa(a, b);
			
		}
		//display_list(*b);
		
	}
}*/

int	min_mouv(t_list *a)
{
	int	i;
	int	tmp;
	int	pos;

	back_to_start(&a);
	i = a->mouv;
	tmp = 0;
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
/*
int entre_deux(int	nb, t_list *b)
{
	int	i;
	int	pos;

	i = nb;
	while (taille_list(b) >= 1)
	{
		if (i > b->nb )
		{
			i = b->nb;
			while (taille_list(b) >= 1)
			{
				if (i < b->nb && b->nb < nb)
				{
					i = b->nb;
				}
				if (b->next == NULL)
				{
					if (i < b->nb && b->nb < nb)
						pos = i;
					return (i);
				}
				b = b->nb;
			}
		}
		if (b->next == NULL)
		{
			if (i > b->nb)
				pos = i;
			return (pos);
			break ;
		}
		b = b->next;
	}
	
}*/

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


void    grand2(t_list **a, t_list **b)
{
	int	tmp;
	int	size;

	while (check_list(*a, *b) == 0)
	{
		while (check_list_a(*a) == 0)
		{
			while (taille_list(*a) >= 1)
			{		
				if (taille_list(*b) < 2)
				{
					pb(b, a);
					
					if ((*b)->next != NULL && (*b)->nb < (*b)->next->nb)
						sb(*b);
				}
				else
				{
					if (*a == NULL)
						break ;
					tmp = 0;
					/*ft_printf("QWERTY\n");
					display_list(*a);
					
					ft_printf("TAILLE\n");
					display_list(*b);*/
					size = taille_list(*a);
					while (tmp < size)
					{
						(*a)->mouv = distance_place_a(*a, tmp) + distance_place(*b, (*a)->nb);
						//ft_printf("MOUV de %d = %d . %d 		\n", (*a)->nb, (*a)->mouv, tmp);
						if ((*a)->next == NULL)
							break ;
						*a = (*a)->next;
						tmp++;
					
					}
					back_to_start(a);
					tmp = min_mouv(*a);
					push_min_second(a, tmp);
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
							else if (min_first(*b) > taille_list(*b) / 2)
							{
								while (tmp < taille_list(*b))
								{
									rrb(b);
									tmp++;
								}
								pb(b, a);
							}
							else
							{
								while (tmp >= 1)
								{
									rb(b);
									tmp--;
								}
								pb(b, a);
							}
						}
						/*else if ((*a)->nb < (*b)->nb && (*a)->nb > (*b)->next->nb)
						{
							tmp = max_two((*a)->nb, *b);
							if (tmp > taille_list(*b) / 2)
							{
								while (tmp < taille_list(*b))
								{
									rrb(b);
									tmp++;
								}
								pb(b, a);
							}
							else
							{
								while (tmp >= 1)
								{
									rb(b);
									tmp--;
								}
								pb(b, a);
							}
						}*/
						else if ((*a)->nb < (*b)->nb && (*a)->nb > (*b)->next->nb)
						{
							pb(b, a);
							sb(*b);
						}
						else if (distance_place2(*b, (*a)->nb) <= taille_list(*b) / 2)
						{
							tmp = distance_place2(*b, (*a)->nb);
							//ft_printf("distance place %d = %d\n", (*a)->nb , tmp);
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
								while (tmp < taille_list(*b))
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
							//ft_printf("sdfjkahsdjkf\n");
							tmp = max_two((*a)->nb, *b);
							//ft_printf("max- TWO = %d\n", tmp);
							if (tmp > taille_list(*b) / 2)
							{
								while (tmp < taille_list(*b))
								{
									rrb(b);
									tmp++;
								}
								pb(b, a);
							}
							else
							{
								while (tmp >= 1)
								{
									rb(b);
									tmp--;
								}
								pb(b, a);
							}
						}
						else			
							pb(b, a);
					}
				}
				//display_list(*b);
			}
			//display_list(*b);
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
			while (*b != NULL)
				pa(a, b);
			//display_list(*a);
		}
	}
}


