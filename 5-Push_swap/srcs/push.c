/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 12:40:09 by ebodart           #+#    #+#             */
/*   Updated: 2021/07/23 09:53:48 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_a(t_stack *stacks)
{
	int	top_a;
	int	top_b;

	top_a = stacks->top_a;
	top_b = stacks->top_b;
	if (stacks->size_b > 0)
	{
		if (top_a > 0)
		{
			stacks->stack_a[top_a - 1] = stacks->stack_b[top_b];
			stacks->stack_b[top_b] = 0;
			stacks->top_a = top_a - 1;
			stacks->top_b = top_b + 1;
			stacks->size_a += 1;
			stacks->size_b -= 1;
		}
	}
}

void	push_b(t_stack *stacks)
{
	int	top_a;
	int	top_b;

	top_a = stacks->top_a;
	top_b = stacks->top_b;
	if (stacks->size_a > 0)
	{
		if (top_b > 0)
		{
			stacks->stack_b[top_b - 1] = stacks->stack_a[top_a];
			stacks->stack_a[top_a] = 0;
			stacks->top_b = top_b - 1;
			stacks->top_a = top_a + 1;
			stacks->size_b += 1;
			stacks->size_a -= 1;
		}
	}
}
