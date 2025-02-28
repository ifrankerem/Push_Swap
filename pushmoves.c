/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushmoves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 00:16:23 by iarslan           #+#    #+#             */
/*   Updated: 2025/03/01 00:52:46 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
