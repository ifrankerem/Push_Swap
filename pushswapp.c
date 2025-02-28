/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswapp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 02:36:24 by iarslan           #+#    #+#             */
/*   Updated: 2025/03/01 00:53:00 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pushswap(t_stack **a, t_stack **b)
{
	int	len_a;

	len_a = ft_lstsize2(*a);
	while (len_a > 3)
	{
		pb(a, b);
		len_a--;
	}
	three(a);
	while (*b)
	{
		re_init_nodes(*a, *b);
		move_nodes(a, b);
	}
	smallest_to_top(a);
}

void	smallest_to_top(t_stack **a)
{
	t_stack	*a_smallest;

	set_current_pos(*a);
	a_smallest = find_smallest_node(*a);
	if (*a != a_smallest)
	{
		if (a_smallest->is_above == 1)
		{
			while (*a != a_smallest)
				ra(a);
		}
		else if (a_smallest->is_above == 0)
		{
			while (*a != a_smallest)
				rra(a);
		}
	}
}
