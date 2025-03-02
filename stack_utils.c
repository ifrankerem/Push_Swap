/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 00:24:51 by iarslan           #+#    #+#             */
/*   Updated: 2025/03/02 03:41:19 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_sorted(t_stack *stack)
{
	int	flag;

	flag = 1;
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
		{
			flag = 0;
			break ;
		}
		stack = stack->next;
	}
	return (flag);
}

void	three(t_stack **a)
{
	int	max;

	max = find_biggest(*a);
	if ((*a)->value == max)
		ra(a);
	else if ((*a)->next->value == max)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

int	find_biggest(t_stack *a)
{
	t_stack	*temp;
	int		max;

	max = a->value;
	temp = a;
	while (temp)
	{
		if (temp->value > max)
			max = temp->value;
		temp = temp->next;
	}
	return (max);
}

t_stack	*find_smallest_node(t_stack *a)
{
	t_stack	*temp;
	t_stack	*temp2;
	int		min;

	temp2 = a;
	min = a->value;
	temp = a;
	while (temp)
	{
		if (temp->value < min)
			min = temp->value;
		temp = temp->next;
	}
	while (temp2)
	{
		if (temp2->value == min)
			return (temp2);
		else
			temp2 = temp2->next;
	}
	return (temp2);
}
