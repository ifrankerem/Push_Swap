/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 00:16:23 by iarslan           #+#    #+#             */
/*   Updated: 2025/02/24 06:08:45 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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
void	pa(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	t_stack	*newnode;

	newnode = ft_lstnew2((*b)->value);
	ft_lstadd_front2(a, newnode);
	temp = *b;
	*b = (*b)->next;
	free(temp);
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	t_stack	*newnode;

	newnode = ft_lstnew2((*a)->value);
	ft_lstadd_front2(b, newnode);
	temp = *a;
	*a = (*a)->next;
	free(temp);
	write(1, "pb\n", 3);
}
