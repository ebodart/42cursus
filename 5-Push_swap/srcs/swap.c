/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 12:31:32 by ebodart           #+#    #+#             */
/*   Updated: 2021/09/05 18:34:18 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_a(t_stack *stacks, int write)
{
	int	tmp;
	int	top_a;

	top_a = stacks->top_a;
	if (stacks->size_a > 1)
	{
		tmp = stacks->st_a[top_a];
		stacks->st_a[top_a] = stacks->st_a[top_a + 1];
		stacks->st_a[top_a + 1] = tmp;
	}
	if (write == 1)
		ft_putendl("sa", STDOUT);
}

void	swap_b(t_stack *stacks, int write)
{
	int	tmp;
	int	top_b;

	top_b = stacks->top_b;
	if (stacks->size_b > 1)
	{
		tmp = stacks->st_b[top_b];
		stacks->st_b[top_b] = stacks->st_b[top_b + 1];
		stacks->st_b[top_b + 1] = tmp;
	}
	if (write == 1)
		ft_putendl("sb", STDOUT);
}

void	swap_ab(t_stack *stacks, int write)
{
	int	tmp;

	if (stacks->size_a > 1)
	{
		tmp = stacks->st_a[0];
		stacks->st_a[0] = stacks->st_a[1];
		stacks->st_a[1] = tmp;
	}
	if (stacks->size_b > 1)
	{
		tmp = stacks->st_b[0];
		stacks->st_b[0] = stacks->st_b[1];
		stacks->st_b[1] = tmp;
	}
	if (write == 1)
		ft_putendl("ss", STDOUT);
}
