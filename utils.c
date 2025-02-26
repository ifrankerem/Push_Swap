/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:50:26 by iarslan           #+#    #+#             */
/*   Updated: 2025/02/26 17:02:41 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pushswap.h"

int	ft_atoi2(const char *nptr)
{
	long	sign;
	long	number;

	number = 0;
	sign = 1;
	while (*nptr == ' ' && *nptr >= 9 && *nptr <= 13)
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr <= '9' && *nptr >= '0')
	{
		number = number * 10 + (*nptr - 48);
		if ((number * sign) < -2147483648 || (number * sign) > 2147483647)
			ft_error(NULL);
		nptr++;
	}
	number = number * sign;
	return (number);
}

int	error_syntax(char *x)
{
	int	i;

	i = 0;
	if ((x[i + 1] == '-' && x[i] == '-') || (x[i] == '+') || (x[i] == '-' && x[i
			+ 1] == '\0') || (x[i] == '\0'))
		return (0);
	if (x[i] == '-')
		i++;
	while (x[i])
	{
		if (x[i] <= '9' && x[i] >= '0')
			i++;
		else
			return (0);
	}
	return (1);
}
int	check_duplicate(t_stack *a, int number)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->value == number)
			return (1);
		a = a->next;
	}
	return (0);
}
t_stack	*ft_lstnew2(int content)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = content;
	node->next = NULL;
	return (node);
}
void	ft_lstadd_front2(t_stack **lst, t_stack *new)
{
	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}
void	ft_lstadd_back2(t_stack **lst, t_stack *new)
{
	t_stack	*current;

	if (!new || !lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	current = *lst;
	while (current->next)
		current = current->next;
	current->next = new;
}
