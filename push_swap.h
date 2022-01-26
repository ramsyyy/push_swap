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

int	check_arg(int argc, char **argv);

t_list	*list_init(int argc, char **argv);
void	*back_to_start(t_list *a);
void	*go_to_end(t_list *a);
void	display_list(t_list *a);

void	sa(t_list *a);



#endif