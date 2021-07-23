/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 12:31:32 by ebodart           #+#    #+#             */
/*   Updated: 2021/07/23 09:50:32 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_a(t_stack *stacks)
{
	int	tmp;
	int	top_a;

	top_a = stacks->top_a;
	if (stacks->size_a > 1)
	{
		tmp = stacks->stack_a[top_a];
		stacks->stack_a[top_a] = stacks->stack_a[top_a + 1];
		stacks->stack_a[top_a + 1] = tmp;
	}
}

void	swap_b(t_stack *stacks)
{
	int	tmp;
	int	top_b;

	top_b = stacks->top_b;
	if (stacks->size_b > 1)
	{
		tmp = stacks->stack_b[top_b];
		stacks->stack_b[top_b] = stacks->stack_b[top_b + 1];
		stacks->stack_b[top_b + 1] = tmp;
	}
}

void	swap_ab(t_stack *stacks)
{
	int	tmp;

	if (stacks->size_a > 1)
	{
		tmp = stacks->stack_a[0];
		stacks->stack_a[0] = stacks->stack_a[1];
		stacks->stack_a[1] = tmp;
	}
	if (stacks->size_b > 1)
	{
		tmp = stacks->stack_b[0];
		stacks->stack_b[0] = stacks->stack_b[1];
		stacks->stack_b[1] = tmp;
	}
}
