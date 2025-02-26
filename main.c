/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 00:16:43 by iarslan           #+#    #+#             */
/*   Updated: 2025/02/27 00:23:30 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pushswap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL; // for segfaults
	if (1 == argc)
		return (1);
	else if (2 == argc)
	{
		argv = ft_split(argv[1], ' ');
		ft_args(&a, argv);
		ft_free_argv(argv);
	}
	else
		ft_args(&a, argv + 1);
	if (!stack_sorted(a))
	{
		if (ft_lstsize2(a) == 2)
			sa(&a);
		else if (ft_lstsize2(a) == 3)
			three(&a);
		else
			pushswap(&a, &b);
	}
	ft_free_stack(&a);
	return (0);
}
