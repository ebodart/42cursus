/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 17:17:49 by ebodart           #+#    #+#             */
/*   Updated: 2021/07/23 09:51:13 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_a(t_stack *stacks)
{
	int	tmp;
	int	top_a;
	int	i;

	top_a = stacks->top_a;
	tmp = stacks->stack_a[top_a];
	i = top_a + 1;
	while (i < stacks->size_total)
	{
		stacks->stack_a[i - 1] = stacks->stack_a[i];
		i++;
	}
	stacks->stack_a[i - 1] = tmp;
}

void	rotate_b(t_stack *stacks)
{
	int	tmp;
	int	top_b;
	int	i;

	top_b = stacks->top_b;
	tmp = stacks->stack_b[top_b];
	i = top_b + 1;
	while (i < stacks->size_total)
	{
		stacks->stack_b[i - 1] = stacks->stack_b[i];
		i++;
	}
	stacks->stack_b[i - 1] = tmp;
}

void	rotate(t_stack *stacks)
{
	rotate_a(&(*stacks));
	rotate_b(&(*stacks));
}
