/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswapp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 02:36:24 by iarslan           #+#    #+#             */
/*   Updated: 2025/02/23 23:49:38 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	pushswap(t_stack **a, t_stack **b)
{
	t_stack *a_smallest;
	if (!(stack_sorted(*a)))
	{
		if (ft_lstsize2(*a) == 2)
		{
			if ((*a)->value > (*a)->next->value)
				sa(*a);
		}
		else if (ft_lstsize2(*a) == 3)
			three(a);
		else
		{
			while (ft_lstsize2(*a) == 3)
				pb(a, b);
			while (*b)
			{
				re_init_nodes(*a, *b);
				move_nodes(a, b);
			}
			set_current_pos(*a);
			a_smallest = find_smallest_node(*a);
			if (*a != a_smallest)
			{
				if (a_smallest->is_above == 1)
				{
					while (*a != a_smallest)
						ra(*a);
				}
				else
				{
					while (*a != a_smallest)
						rra(*a);
				}
			}
		}
	}
}
