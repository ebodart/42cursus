/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 12:07:54 by ebodart           #+#    #+#             */
/*   Updated: 2021/10/04 09:50:26 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_free_line_exit_error(t_stack *stacks, char *line)
{
	free(line);
	free(stacks->st_a);
	free(stacks->st_b);
	ft_putendl("Error", STDERR);
	exit(0);
}

void	ft_free_exit_error(t_stack *stacks)
{
	free(stacks->st_a);
	free(stacks->st_b);
	ft_putendl("Error", STDERR);
	exit(0);
}

void	ft_free_exit_success(t_stack *stacks)
{	
	free(stacks->st_a);
	free(stacks->st_b);
	exit(0);
}

void	ft_free_exit_ok(t_stack *stacks)
{	
	free(stacks->st_a);
	free(stacks->st_b);
	ft_putendl("OK", STDOUT);
	exit(0);
}

void	ft_free_exit_ko(t_stack *stacks)
{	
	free(stacks->st_a);
	free(stacks->st_b);
	ft_putendl("KO", STDOUT);
	exit(0);
}
