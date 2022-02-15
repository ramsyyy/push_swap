/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grand3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaga <raaga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:29:17 by raaga             #+#    #+#             */
/*   Updated: 2022/02/15 19:26:36 by raaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int distance_place3(t_list *b, int nb)
{
    int	i;

	i = 0;
	back_to_start(&b);
	if (b == NULL)
		return (0);
	while (b != NULL && nb != b->nb)
	{
		if (b->next != NULL)
		{
			b = b->next;
            i++;
		}
		else
			break ;
	}
	back_to_start(&b);
    i = distance_place_a(b, i);
	return (i);
}

int distance_place4(t_list *a, int nb)
{
	int	i;
    int j;
    t_tab tab;
    
	i = 0;
	back_to_start(&a);
    tab = check_chunk(a);
	if (a == NULL)
		return (0);
	while (nb > tab.tab[i] && i < tab.size)
    { 
        i++;
    }
    j = 0;
    while (a->nb != tab.tab[i])
    {
        //ft_printf("qweqweqweqweqw = %d = %d\n", a->nb, tab.tab[i]);
        if (a->next != NULL)
        {
            a = a->next;
            j++;
        }
        else
            break ;
    }
	return (j);
}
void	nb_mouv2(t_list **a, t_list **b)
{
	int	tmp;
	int	size;
	
	tmp = 0;
	size = taille_list(*b);
	while (tmp < size)
	{
		(*b)->mouv = distance_place3(*b, (*b)->nb) + distance_place4(*a, (*b)->nb);
		//ft_printf("QWERTY %d = %d\n", (*b)->nb,  (*b)->mouv);
		if ((*b)->next == NULL)
			break ;
		*b = (*b)->next;
		tmp++;
	}
	back_to_start(b);
}

void	mediane(t_list **a, t_list **b)
{
	int mediane;
	int	max;
	t_tab tab;
	
	tab = check_chunk(*a);
	max = tab.size - 1;
	mediane = tab.tab[tab.size / 2];
    
    int i = 0;
    while (i < tab.size)
    {
       // ft_printf("tab[%d] = %d\n", i, tab.size);
        i++;
    }
	while (taille_list(*a) > 3)
	{
		if ((*a)->nb == tab.tab[max] || (*a)->nb == tab.tab[max - 1] || (*a)->nb == tab.tab[max - 2])
			ra(a);
        pb(b, a);
		if ((*b)->nb > mediane && taille_list(*b) > 1)
			rb(b);
       
	}
    petit(a, b);
}

void	push_min3(t_list **b, t_list **a, int min)
{
    int i;

    i = distance_place4(*a, nb_index(*b, min));
    (void)a;
	if (min > taille_list(*b) / 2)
	{
		while (min <= taille_list(*b))
		{
            if (i >= taille_list(*a) / 2)
                rrr(a, b);
            else
			    rrb(b);
			min++;
		}
	}
	else
	{
		while (min > 1)
		{
            if (i <= taille_list(*a) / 2)
                rr(a, b);
			else
                rb(b);
			min--;
		}
	}
}

void push_position(t_list **a, t_list **b)
{
    int i;

    i = distance_place4(*a, (*b)->nb);
    if (i > taille_list(*a) / 2)
    {
        while (i < taille_list(*a))
        {
            rra(a);
            i++;
        }
        pa(a, b);
    }
    else
    {
        while (i >= 1)
        {
            ra(a);
            i--;
        }
        pa(a, b);
    }
    
}

void	grand3(t_list **a, t_list **b)
{
	int	tmp;
	int max;
	if (check_list(*a, *b) == 0)
	{
		mediane(a, b);
		//display_list(*a);
        max = (*a)->next->next->nb;
       /* display_list(*a);
        ft_printf("/////\n");*/
       /* tmp = 30;
        while (tmp > 0)
        {
            rrb(b);
            tmp--;
        }*/
		if (check_list_b(*b) == 0)
		{
			while (taille_list(*b) >= 1)
			{
                //display_list(*b);
				//display_list(*a);
				nb_mouv2(a, b);
				//ft_printf("QWERTYUIO %d\n", min_mouv(*b));
				back_to_start(b);
                tmp = min_mouv(*b);
                push_min3(b, a, tmp);
                push_position(a, b);
               /* ft_printf("AAAAAAA = \n");
                display_list(*a);
                ft_printf("FIN AA \n");*/
            }
        }
	}
    tmp = 1;
    back_to_start(a);
    while (max != (*a)->nb)
    {
        (*a) = (*a)->next;
        tmp++;   
    }
    back_to_start(a);
    if (tmp != taille_list(*a))
	{
       
		if (tmp > taille_list(*a) / 2)
		{
            
			while (tmp < taille_list(*a))
			{
				rra(a);
				tmp++;
			}
		}
		else 
		{
			while (tmp >= 1)
			{
				ra(a);
				tmp--;
			}
		}
	}
    //display_list(*a);
}