/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverserotatemoves.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 01:38:17 by iarslan           #+#    #+#             */
/*   Updated: 2025/02/27 01:44:01 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrx(t_stack **a)
{
	t_stack	*second_last;
	t_stack	*last;

	second_last = NULL;
	last = *a;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *a;
	*a = last;
}

void	rra(t_stack **a)
{
	rrx(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	rrx(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	rrx(a);
	rrx(b);
	write(1, "rrr\n", 4);
}
