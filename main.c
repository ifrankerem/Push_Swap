/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 00:16:43 by iarslan           #+#    #+#             */
/*   Updated: 2025/02/24 03:26:52 by iarslan          ###   ########.fr       */
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
	if (1 == argc || (2 == argc && !argv[1][0]))
		return (1);
	else if (2 == argc)
	{
		argv = ft_split(argv[1], ' ');
		ft_args(&a, argv);
		ft_free_argv(argv);
	}
	else
		ft_args(&a, argv + 1);
	pushswap(&a, &b);
	ft_free_stack(&a);
	return (0);
}
