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

typedef struct s_moy t_moy;
struct s_moy
{
	int	taille;
	int	total;
	int	moy;
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
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);

int		taille_list(t_list *a);
int		addition_list(t_list *a);
int		moyen_list(t_list *a);
void	algo(t_list **a, t_list **b);
void	petit(t_list **a, t_list **b);
void	moyen(t_list **a, t_list **b);
void	grand(t_list **a, t_list **b);
void    grand2(t_list **a, t_list **b);

int	min_first(t_list *a);
int	min_second(t_list *a);
int	distance(int var, t_list *a);

int	list_dernier(t_list *a);
int	check_list_b(t_list *a);
int	check_list_a(t_list *a);
int	check_list(t_list *a, t_list *b);
void	push_min(t_list **a, t_list **b, int min);
int	verif_b(int nb, t_list *b);
int	nb_index(t_list *a, int index);
int	list_i(t_list *a, int	place);
int distance_place(t_list *b, int nb);
void	push_min_second(t_list **a, t_list **b, int min);

#endif