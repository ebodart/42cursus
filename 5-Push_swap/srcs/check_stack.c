/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 20:08:27 by ebodart           #+#    #+#             */
/*   Updated: 2021/08/18 21:09:23 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_check_sorted(t_stack *stacks)
{
	int	i;

	i = 0;
	while (stacks->st_a[i] < stacks->st_a[i + 1])
	{
		i++;
		if (i == stacks->size_tot - 1)
			ft_free_exit_success(&(*stacks));
	}
}

void	ft_check_duplicate(t_stack *stacks, int s, int value)
{
	if (s >= 1)
	{
		while (s > 0)
		{
			if (stacks->st_a[s - 1] == value)
			{
				ft_free_exit_error(&(*stacks));
			}
			else
				s--;
		}
	}
}
