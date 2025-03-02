/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 01:41:49 by iarslan           #+#    #+#             */
/*   Updated: 2025/03/02 03:15:22 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

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

void			ft_error(t_stack **stack, char **argv, int use_split);
void			ft_free_stack(t_stack **stack);
int				error_syntax(char *x);
int				check_duplicate(t_stack *a, int number);
int				ft_atoi2(const char *nptr, t_stack **stack, char *argv[],
					int use_split);
void			ft_args(t_stack **a, char *argv[], int use_split);
void			ft_lstadd_front2(t_stack **lst, t_stack *new);
t_stack			*ft_lstnew2(int content);
void			ft_free_argv(char **argv);
int				stack_sorted(t_stack *x);
void			sx(t_stack **a);
void			sb(t_stack **b);
void			sa(t_stack **a);
void			ss(t_stack **a, t_stack **b);
void			pa(t_stack **a, t_stack **b);
void			pb(t_stack **a, t_stack **b);
void			ra(t_stack **a);
void			rb(t_stack **b);
void			rr(t_stack **a, t_stack **b);
void			rrx(t_stack **a);
void			rra(t_stack **a);
void			rrb(t_stack **b);
void			rrr(t_stack **a, t_stack **b);
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
void			ft_lstadd_back2(t_stack **lst, t_stack *new);
void			smallest_to_top(t_stack **a);

#endif