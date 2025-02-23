/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 00:16:23 by iarslan           #+#    #+#             */
/*   Updated: 2025/02/22 18:16:57 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sa(t_stack *a)
{
	int	temp;

	temp = 0;
	if (!a || !a->next)
		return ;
	temp = a->value;
	a->value = a->next->value;
	a->next->value = temp;
	write(1, "sa\n", 3);
}
void	sb(t_stack *b)
{
	int	temp;

	temp = 0;
	if (!b || b->next)
		return ;
	temp = b->value;
	b->value = b->next->value;
	b->next->value = temp;
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	int	temp;

	temp = 0;
	if (!a || !a->next)
		return ;
	temp = a->value;
	a->value = a->next->value;
	a->next->value = temp;
	temp = 0;
	if (!b || b->next)
		return ;
	temp = b->value;
	b->value = b->next->value;
	b->next->value = temp;
	write(1, "ss\n", 3);
}
void	pa(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	t_stack	*newnode;

	if (!b || !(*b))
		return ;
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

	if (!b || !(*b))
		return ;
	newnode = ft_lstnew2((*a)->value);
	ft_lstadd_front2(b, newnode);
	temp = *a;
	*a = (*a)->next;
	free(temp);
	write(1, "pb\n", 3);
}
