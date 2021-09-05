/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 12:07:54 by ebodart           #+#    #+#             */
/*   Updated: 2021/09/05 20:24:16 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_exit_error(void)
{
	ft_putendl("Error", STDERR);
	exit(EXIT_SUCCESS);
}

void	ft_free_exit_error(t_stack *stacks)
{
	free(stacks->st_a);
	free(stacks->st_b);
	ft_putendl("Error", STDERR);
	exit(EXIT_SUCCESS);
}

void	ft_free_exit_success(t_stack *stacks)
{	
	free(stacks->st_a);
	free(stacks->st_b);
	exit(EXIT_SUCCESS);
}

void	ft_free_exit_OK(t_stack *stacks)
{	
	free(stacks->st_a);
	free(stacks->st_b);
	ft_putendl("OK", STDOUT);
	exit(EXIT_SUCCESS);
}

void	ft_free_exit_KO(t_stack *stacks)
{	
	free(stacks->st_a);
	free(stacks->st_b);
	ft_putendl("KO", STDOUT);
	exit(EXIT_SUCCESS);
}
