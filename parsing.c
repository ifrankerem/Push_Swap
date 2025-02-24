/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 19:52:31 by iarslan           #+#    #+#             */
/*   Updated: 2025/02/24 03:33:38 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_args(t_stack **a, char *argv[])
{
	int		i;
	int		number;
	t_stack	*node;

	i = 0;
	number = 0;
	while (argv[i])
	{
		if (!error_syntax(argv[i]))
			ft_error(a);
		number = ft_atoi2(argv[i]);
		if (check_duplicate(*a, number))
			ft_error(a);
		node = ft_lstnew2(number);
		if (!node)
			ft_error(a);
		ft_lstadd_back2(a, node);
		i++;
	}
}
