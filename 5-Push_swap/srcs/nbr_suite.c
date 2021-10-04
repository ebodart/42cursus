/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_suite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 11:24:19 by ebodart           #+#    #+#             */
/*   Updated: 2021/10/02 17:22:12 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_smallest_index(int i, int j, t_stack *stacks)
{
	long int	tmp;
	int			index;

	while (j < stacks->size_tot)
	{
		if (j == 0)
		{
			while (stacks->st_a[j] < i)
				j++;
			tmp = stacks->st_a[j];
			index = j;
			j++;
		}
		if (stacks->st_a[j] < tmp && stacks->st_a[j] >= i)
		{
			tmp = stacks->st_a[j];
			index = j;
		}
		j++;
	}
	return (index);
}

void	ft_nbr_suite(t_stack *stacks, int first_a)
{
	int	i;
	int	j;
	int	index;

	i = 1;
	stacks->st_a[first_a] = 0;
	while (i < stacks->size_tot)
	{
		j = 0;
		index = ft_smallest_index(i, j, &(*stacks));
		stacks->st_a[index] = i;
		i++;
	}
}
