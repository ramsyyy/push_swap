#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include "./printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list t_list;
struct s_list
{
	int nb;
	t_list *prev;
	t_list *next;
};

char	**ft_split_mod(char const *s, char c, char *str);
int		check_arg(int argc, char **argv);
char	**list_atoi(char **argv);
int		count_split(char **split);

t_list	*list_init(int argc, char **argv);
void	back_to_start(t_list **a);
void	go_to_end(t_list **a);
void	display_list(t_list *a);
t_list	*ft_lstnew(int nb);

void	sasb(t_list *a);
void	ft_pb(t_list **b, t_list **a);
void    ft_ra(t_list **a);
void    ft_rra(t_list **a);

void    sa(t_list *a);
void	sb(t_list *b);
void	ss(t_list *a, t_list *b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **b, t_list **a);
void	ra(t_list *a);
void	rb(t_list *b);
void	rr(t_list *a, t_list *b);
void	rra(t_list *a);
void	rrb(t_list *b);
void	rrr(t_list *a, t_list *b);

#endif