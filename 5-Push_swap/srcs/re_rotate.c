/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 09:25:41 by ebodart           #+#    #+#             */
/*   Updated: 2021/07/23 09:51:40 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	re_rotate_a(t_stack *stacks)
{
	int	tmp;
	int	top_a;
	int	i;

	top_a = stacks->top_a;
	i = stacks->size_total - 1;
	tmp = stacks->stack_a[i];
	while (i > top_a)
	{
		stacks->stack_a[i] = stacks->stack_a[i - 1];
		i--;
	}
	stacks->stack_a[i] = tmp;
}

void	re_rotate_b(t_stack *stacks)
{
	int	tmp;
	int	top_b;
	int	i;

	top_b = stacks->top_b;
	i = stacks->size_total - 1;
	tmp = stacks->stack_b[i];
	while (i > top_b)
	{
		stacks->stack_b[i] = stacks->stack_b[i - 1];
		i--;
	}
	stacks->stack_b[i] = tmp;
}

void	re_rotate(t_stack *stacks)
{
	re_rotate_a(&(*stacks));
	re_rotate_b(&(*stacks));
}
