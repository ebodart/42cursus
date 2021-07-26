/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 09:25:41 by ebodart           #+#    #+#             */
/*   Updated: 2021/07/26 17:55:23 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	re_rotate_a(t_stack *stacks)
{
	int	tmp;
	int	top_a;
	int	i;

	top_a = stacks->top_a;
	i = stacks->size_tot - 1;
	tmp = stacks->st_a[i];
	while (i > top_a)
	{
		stacks->st_a[i] = stacks->st_a[i - 1];
		i--;
	}
	stacks->st_a[i] = tmp;
	ft_putendl("rra", STDOUT);
}

void	re_rotate_b(t_stack *stacks)
{
	int	tmp;
	int	top_b;
	int	i;

	top_b = stacks->top_b;
	i = stacks->size_tot - 1;
	tmp = stacks->st_b[i];
	while (i > top_b)
	{
		stacks->st_b[i] = stacks->st_b[i - 1];
		i--;
	}
	stacks->st_b[i] = tmp;
	ft_putendl("rrb", STDOUT);
}

void	re_rotate(t_stack *stacks)
{
	int	tmp;
	int	top_a;
	int	top_b;
	int	i;

	top_a = stacks->top_a;
	i = stacks->size_tot - 1;
	tmp = stacks->st_a[i];
	while (i > top_a)
	{
		stacks->st_a[i] = stacks->st_a[i - 1];
		i--;
	}
	stacks->st_a[i] = tmp;
	top_b = stacks->top_b;
	i = stacks->size_tot - 1;
	tmp = stacks->st_b[i];
	while (i > top_b)
	{
		stacks->st_b[i] = stacks->st_b[i - 1];
		i--;
	}
	stacks->st_b[i] = tmp;
	ft_putendl("rrr", STDOUT);
}