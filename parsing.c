/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 19:52:31 by iarslan           #+#    #+#             */
/*   Updated: 2025/03/02 04:01:11 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_args(t_stack **a, char *argv[], int use_split)
{
	int		len;
	int		number;
	t_stack	*node;

	len = 0;
	if (!argv || !argv[0])
		ft_error(a, argv, use_split);
	while (argv[len])
		len++;
	if (len == 0)
		ft_error(a, argv, use_split);
	number = 0;
	while (len > 0)
	{
		if (!error_syntax(argv[len - 1]))
			ft_error(a, argv, use_split);
		number = ft_atoi2(argv[len - 1], a, argv, use_split);
		if (check_duplicate(*a, number))
			ft_error(a, argv, use_split);
		node = ft_lstnew2(number);
		if (!node)
			return (ft_error(a, argv, use_split));
		ft_lstadd_front2(a, node);
		len--;
	}
}
