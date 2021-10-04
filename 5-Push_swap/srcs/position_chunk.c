/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_chunk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 19:06:41 by ebodart           #+#    #+#             */
/*   Updated: 2021/10/03 18:45:52 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_top_chunk(t_stack *stacks, int nbr_chu, int max)
{
	int	min_ch;
	int	max_ch;
	int	i;

	i = stacks->top_a;
	min_ch = (stacks->size_tot / max) * (nbr_chu - 1);
	max_ch = (stacks->size_tot / max) * (nbr_chu);
	if (nbr_chu == max)
		max_ch = stacks->size_tot;
	while (i < stacks->size_tot)
	{
		if (stacks->st_a[i] >= min_ch && stacks->st_a[i] < max_ch)
			return (i);
		else
			i++;
	}
	return (-1);
}

int	ft_bottom_chunk(t_stack *stacks, int nbr_chu, int max)
{
	int	min_ch;
	int	max_ch;
	int	i;

	i = stacks->size_tot - 1;
	min_ch = (stacks->size_tot / max) * (nbr_chu - 1);
	max_ch = (stacks->size_tot / max) * (nbr_chu);
	if (nbr_chu == max)
		max_ch = stacks->size_tot;
	while (i >= stacks->top_a)
	{
		if (stacks->st_a[i] >= min_ch && stacks->st_a[i] < max_ch)
			return (i);
		else
			i--;
	}
	return (-1);
}

int	ft_previous_b(t_stack *stacks, int nbr)
{
	int	i;
	int	previous;	

	previous = -1;
	i = stacks->top_b;
	if (nbr < stacks->st_b[ft_first_b(&(*stacks))])
		return (ft_last_b(&(*stacks)));
	while (i < stacks->size_tot)
	{
		while (previous == -1)
		{
			if (stacks->st_b[i] < nbr && stacks->st_b[i] > -1)
				previous = i;
			i++;
		}
		if (stacks->st_b[i] < nbr && stacks->st_b[i] > stacks->st_b[previous])
			previous = i;
		i++;
	}
	return (previous);
}
