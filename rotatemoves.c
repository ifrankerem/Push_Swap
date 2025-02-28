/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotatemoves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 01:39:42 by iarslan           #+#    #+#             */
/*   Updated: 2025/02/27 01:44:04 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rx(t_stack **a)
{
	t_stack	*first;
	t_stack	*last;

	first = *a;
	last = *a;
	(*a) = (*a)->next;
	while (last->next)
		last = last->next;
	first->next = NULL;
	last->next = first;
}

void	rb(t_stack **b)
{
	rx(b);
	write(1, "rb\n", 3);
}

void	ra(t_stack **a)
{
	rx(a);
	write(1, "ra\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	rx(a);
	rx(b);
	write(1, "rr\n", 3);
}
