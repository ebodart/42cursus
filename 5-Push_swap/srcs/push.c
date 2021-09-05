/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 12:40:09 by ebodart           #+#    #+#             */
/*   Updated: 2021/09/05 18:34:44 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_a(t_stack *stacks, int write)
{
	int	top_a;
	int	top_b;

	top_a = stacks->top_a;
	top_b = stacks->top_b;
	if (stacks->size_b > 0)
	{
		if (top_a > 0)
		{
			stacks->st_a[top_a - 1] = stacks->st_b[top_b];
			stacks->st_b[top_b] = 0;
			stacks->top_a = top_a - 1;
			stacks->top_b = top_b + 1;
			stacks->size_a += 1;
			stacks->size_b -= 1;
		}
	}
	if (write == 1)
		ft_putendl("pa", STDOUT);
}

void	push_b(t_stack *stacks, int write)
{
	int	top_a;
	int	top_b;

	top_a = stacks->top_a;
	top_b = stacks->top_b;
	if (stacks->size_a > 0)
	{
		if (top_b > 0)
		{
			stacks->st_b[top_b - 1] = stacks->st_a[top_a];
			stacks->st_a[top_a] = 0;
			stacks->top_b = top_b - 1;
			stacks->top_a = top_a + 1;
			stacks->size_b += 1;
			stacks->size_a -= 1;
		}
	}
	if (write == 1)
		ft_putendl("pb", STDOUT);
}
