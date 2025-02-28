/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkishalgo2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:10:08 by iarslan           #+#    #+#             */
/*   Updated: 2025/02/27 16:12:30 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_nodes(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = return_cheapest_node(*b);
	if (cheapest->is_above && cheapest->target_node->is_above)
		rotate_both(a, b, cheapest);
	else if (!(cheapest->is_above) && !(cheapest->is_above))
		reverse_rotate_both(a, b, cheapest);
	finish_rotation(a, cheapest->target_node, 'a');
	finish_rotation(b, cheapest, 'b');
	pa(a, b);
}

void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (((*b) != cheapest_node) && (*a) != cheapest_node->target_node)
		rr(a, b);
	set_current_pos(*a);
	set_current_pos(*b);
}

void	reverse_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (((*b) != cheapest_node) && (*a) != cheapest_node->target_node)
		rrr(a, b);
	set_current_pos(*a);
	set_current_pos(*b);
}

void	finish_rotation(t_stack **stack, t_stack *top_node, char stack_name)
{
	if (stack_name == 'a')
	{
		while ((*stack) != top_node)
		{
			if (top_node->is_above == 1)
				ra(stack);
			else
				rra(stack);
		}
	}
	else if (stack_name == 'b')
	{
		while ((*stack) != top_node)
		{
			if (top_node->is_above == 1)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

void	re_init_nodes(t_stack *a, t_stack *b)
{
	set_current_pos(a);
	set_current_pos(b);
	target_node(a, b);
	set_price(a, b);
	set_cheapest(b);
}
