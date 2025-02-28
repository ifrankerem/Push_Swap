/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkishalgo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 01:25:02 by iarslan           #+#    #+#             */
/*   Updated: 2025/03/01 00:55:12 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	target_node(t_stack *a, t_stack *b)
{
	int		best_match;
	t_stack	*a_current;

	while (b)
	{
		best_match = 2147483647;
		a_current = a;
		while (a_current)
		{
			if ((b->value < a_current->value) && a_current->value < best_match)
			{
				best_match = a_current->value;
				b->target_node = a_current;
			}
			a_current = a_current->next;
		}
		if (best_match == 2147483647)
			b->target_node = find_smallest_node(a);
		b = b->next;
	}
}

void	set_current_pos(t_stack *root)
{
	int	len;
	int	i;

	len = ft_lstsize2(root);
	i = 0;
	while (root)
	{
		root->current_pos = i;
		if (i <= (len / 2))
			root->is_above = 1;
		else
			root->is_above = 0;
		root = root->next;
		i++;
	}
}

void	set_price(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = ft_lstsize2(a);
	len_b = ft_lstsize2(b);
	while (b)
	{
		if (b->is_above == 1)
			b->pushprice = b->current_pos;
		else
			b->pushprice = len_b - (b->current_pos);
		if (b->target_node->is_above == 1)
			b->pushprice = b->pushprice + b->target_node->current_pos;
		else
			b->pushprice = b->pushprice + (len_a
					- (b->target_node->current_pos));
		b = b->next;
	}
}

void	set_cheapest(t_stack *b)
{
	int		best_match_value;
	t_stack	*cheapest_node;

	if (!b)
		return ;
	best_match_value = 2147483647;
	cheapest_node = NULL;
	while (b)
	{
		b->is_cheapest = 0;
		if (b->pushprice < best_match_value)
		{
			best_match_value = b->pushprice;
			cheapest_node = b;
		}
		b = b->next;
	}
	cheapest_node->is_cheapest = 1;
}

t_stack	*return_cheapest_node(t_stack *b)
{
	while (b)
	{
		if (b->is_cheapest == 1)
			return (b);
		b = b->next;
	}
	return (NULL);
}
