/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 12:16:57 by ebodart           #+#    #+#             */
/*   Updated: 2021/07/23 14:03:07 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_first(t_stack *stacks)
{
	int i;
	int first;

	i = 1;
	first = 0;
	while (i < stacks->size_tot)
	{
		if (stacks->st_a[i] < stacks->st_a[first])
			first = i;
		i++;
	}
	return (first);
}

int	ft_second(t_stack *stacks, int first)
{
	int i;
	int second;

	i = 1;
	second = 0;
	if (first == 0)
		second == stacks->st_a[1];
	while (i < stacks->size_tot)
	{
		if (stacks->st_a[i] < stacks->st_a[second] && i != first)
			second = i;
		i++;
	}
	return (second);
}

void	ft_small_algo(t_stack *stacks)
{
	int	first;
	int	second;

	first = ft_first(&(*stacks));
	second = ft_second(&(*stacks), first);
	printf("first = %i\n", stacks->st_a[first]);
	printf("second = %i\n", stacks->st_a[second]);
}
