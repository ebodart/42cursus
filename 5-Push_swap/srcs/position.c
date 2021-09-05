/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 18:03:47 by ebodart           #+#    #+#             */
/*   Updated: 2021/09/05 19:07:17 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_first_a(t_stack *stacks)
{
	int	i;
	int	first_a;

	first_a = stacks->top_a;
	i = first_a + 1;
	while (i < stacks->size_tot)
	{
		if (stacks->st_a[i] < stacks->st_a[first_a])
			first_a = i;
		i++;
	}
	return (first_a);
}

int	ft_first_b(t_stack *stacks)
{
	int	i;
	int	first_b;

	first_b = stacks->top_b;
	i = first_b + 1;
	while (i < stacks->size_tot)
	{
		if (stacks->st_b[i] < stacks->st_b[first_b])
			first_b = i;
		i++;
	}
	return (first_b);
}

int	ft_second_a(t_stack *stacks, int first_a)
{
	int	i;
	int	second_a;

	second_a = stacks->top_a;
	i = second_a + 1;
	if (first_a == stacks->top_a)
	{
		second_a = stacks->top_a + 1;
		i++;
	}
	while (i < stacks->size_tot)
	{
		if (stacks->st_a[i] < stacks->st_a[second_a] && i != first_a)
			second_a = i;
		i++;
	}
	return (second_a);
}

int	ft_last_a(t_stack *stacks)
{
	int	i;
	int	last_a;

	last_a = stacks->top_a;
	i = last_a + 1;
	while (i < stacks->size_tot)
	{
		if (stacks->st_a[i] > stacks->st_a[last_a])
			last_a = i;
		i++;
	}
	return (last_a);
}

int	ft_last_b(t_stack *stacks)
{
	int	i;
	int	last_b;

	last_b = stacks->top_b;
	i = last_b + 1;
	while (i < stacks->size_tot)
	{
		if (stacks->st_b[i] > stacks->st_b[last_b])
			last_b = i;
		i++;
	}
	return (last_b);
}
