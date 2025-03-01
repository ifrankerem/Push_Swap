/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 19:52:31 by iarslan           #+#    #+#             */
/*   Updated: 2025/03/01 18:32:00 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_args(t_stack **a, char *argv[])
{
	int		len;
	int		number;
	t_stack	*node;

	len = 0;
	if (!argv || !argv[0])
		return (ft_error(a));
	while (argv[len])
		len++;
	if (len == 0)
		ft_error(a);
	number = 0;
	while (len > 0)
	{
		if (!error_syntax(argv[len - 1]))
			ft_error(a);
		number = ft_atoi2(argv[len - 1]);
		if (check_duplicate(*a, number))
			ft_error(a);
		node = ft_lstnew2(number);
		if (!node)
			ft_error(a);
		ft_lstadd_front2(a, node);
		len--;
	}
}
