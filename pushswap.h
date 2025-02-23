#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct node
{
	int			value;
	struct node	*next;
	struct node	*target_node;
	int			pushprice;
	int			current_pos;
	int			is_above;
	int			is_cheapest;
}				t_stack;

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void			ft_error(t_stack **stack);
void			ft_free_stack(t_stack **stack);
int				ft_atoi2(const char *nptr);
int				error_syntax(char *x);
int				check_duplicate(t_stack *a, int number);
char			**split(char const *s, char c);
void			ft_args(t_stack **a, char *argv[]);
void			ft_lstadd_front2(t_stack **lst, t_stack *new);
t_stack			*ft_lstnew2(int content);
void			ft_free_argv(char **argv);
int				stack_sorted(t_stack *x);
void			sa(t_stack *a);
void			sb(t_stack *b);
void			ss(t_stack *a, t_stack *b);
void			pa(t_stack **a, t_stack **b);
void			pb(t_stack **a, t_stack **b);
void			ra(t_stack *a);
void			rb(t_stack *b);
void			rr(t_stack *a, t_stack *b);
void			rrx(t_stack *a);
void			rra(t_stack *a);
void			rrb(t_stack *b);
void			rrr(t_stack *a, t_stack *b);
void			three(t_stack **a);
int				find_biggest(t_stack *a);
t_stack			*find_smallest_node(t_stack *a);
int				ft_lstsize2(t_stack *lst);
void			pushswap(t_stack **a, t_stack **b);
void			target_node(t_stack *a, t_stack *b);
void			set_current_pos(t_stack *root);
void			set_price(t_stack *a, t_stack *b);
void			set_cheapest(t_stack *b);
t_stack			*return_cheapest_node(t_stack *b);
void			move_nodes(t_stack **a, t_stack **b);
void			rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void			reverse_rotate_both(t_stack **a, t_stack **b,
					t_stack *cheapest_node);
void			finish_rotation(t_stack **stack, t_stack *cheapest_node,
					char stack_name);
void			re_init_nodes(t_stack *a, t_stack *b);
#endif