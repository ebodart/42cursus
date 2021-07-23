/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 12:07:54 by ebodart           #+#    #+#             */
/*   Updated: 2021/07/23 09:54:59 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_putendl(char *s)
{
	int	i;

	i = 0;
	while (!(!s) && s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	ft_exit_error(void)
{
	ft_putendl("Error");
	exit(EXIT_SUCCESS);
}

void	ft_free_exit_error(t_stack *stacks)
{
	free(stacks->stack_a);
	free(stacks->stack_b);
	ft_putendl("Error");
	exit(EXIT_SUCCESS);
}

void	ft_free_exit_success(t_stack *stacks)
{
	free(stacks->stack_a);
	free(stacks->stack_b);
	exit(EXIT_SUCCESS);
}
