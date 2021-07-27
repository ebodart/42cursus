/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 12:07:54 by ebodart           #+#    #+#             */
/*   Updated: 2021/07/26 23:12:33 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_exit_error(void)
{
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
	//ft_printf_st_ab(&(*stacks));
	free(stacks->st_a);
	free(stacks->st_b);
	exit(EXIT_SUCCESS);
}
