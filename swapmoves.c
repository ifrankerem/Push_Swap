/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapmoves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 01:36:47 by iarslan           #+#    #+#             */
/*   Updated: 2025/02/27 03:08:26 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sx(t_stack **a)
{
	t_stack	*first;
	t_stack	*second;

	first = *a;
	second = (*a)->next;
	first->next = second->next;
	second->next = first;
	*a = second;
}

void	sb(t_stack **b)
{
	sx(b);
	write(1, "sb\n", 3);
}

void	sa(t_stack **a)
{
	sx(a);
	write(1, "sa\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	sx(a);
	sx(b);
	write(1, "ss\n", 3);
}
