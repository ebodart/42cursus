/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 17:17:49 by ebodart           #+#    #+#             */
/*   Updated: 2021/07/26 17:55:34 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_a(t_stack *stacks)
{
	int	tmp;
	int	top_a;
	int	i;

	top_a = stacks->top_a;
	tmp = stacks->st_a[top_a];
	i = top_a + 1;
	while (i < stacks->size_tot)
	{
		stacks->st_a[i - 1] = stacks->st_a[i];
		i++;
	}
	stacks->st_a[i - 1] = tmp;
	ft_putendl("ra", STDOUT);
}

void	rotate_b(t_stack *stacks)
{
	int	tmp;
	int	top_b;
	int	i;

	top_b = stacks->top_b;
	tmp = stacks->st_b[top_b];
	i = top_b + 1;
	while (i < stacks->size_tot)
	{
		stacks->st_b[i - 1] = stacks->st_b[i];
		i++;
	}
	stacks->st_b[i - 1] = tmp;
	ft_putendl("rb", STDOUT);
}

void	rotate(t_stack *stacks)
{
	int	tmp;
	int	top_a;
	int	top_b;
	int	i;

	top_a = stacks->top_a;
	tmp = stacks->st_a[top_a];
	i = top_a + 1;
	while (i < stacks->size_tot)
	{
		stacks->st_a[i - 1] = stacks->st_a[i];
		i++;
	}
	stacks->st_a[i - 1] = tmp;
	top_b = stacks->top_b;
	tmp = stacks->st_b[top_b];
	i = top_b + 1;
	while (i < stacks->size_tot)
	{
		stacks->st_b[i - 1] = stacks->st_b[i];
		i++;
	}
	stacks->st_b[i - 1] = tmp;
	ft_putendl("rr", STDOUT);
}
