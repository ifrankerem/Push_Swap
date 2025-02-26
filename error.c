/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 00:16:30 by iarslan           #+#    #+#             */
/*   Updated: 2025/02/26 16:37:51 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_error(t_stack **stack)
{
	t_stack	*temp;

	if (!stack || !(*stack))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	write(2, "Error\n", 6);
	*stack = NULL;
	exit(1);
}
void	ft_free_stack(t_stack **stack)
{
	t_stack	*temp;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
}
void	ft_free_argv(char **argv)
{
	int i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}