/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 00:24:51 by iarslan           #+#    #+#             */
/*   Updated: 2025/02/25 17:18:00 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	stack_sorted(t_stack *x)
{
	int		flag;
	t_stack	*temp;

	flag = 0;
	temp = x;
	while (x->next)
	{
		temp = x->next;
		while (temp->next)
		{
			if (x->value < temp->value)
				flag = 1;
			else
				flag = 0;
			temp = temp->next;
		}
		x = x->next;
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
	int		min;
	t_stack	*temp2;

	temp2 = a;
	min = a->value;
	temp = a;
	while (temp)
	{
		if (temp->value < min)
			min = temp->value;
		temp = temp->next;
	}
	while (temp2->value != min)
	{
		if (temp2->value == min)
			return (temp2);
		else
			temp2 = temp2->next;
	}
	return (temp2);
}

int	ft_lstsize2(t_stack *lst)
{
	int	i;

	if (!lst)
		return (0);
	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
