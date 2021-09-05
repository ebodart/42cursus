/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 11:45:51 by ebodart           #+#    #+#             */
/*   Updated: 2021/09/05 19:07:04 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_ra_or_rra(int top, int bottom, int max, t_stack *stacks)
{
	int	top_a;
	int	size;
	int	a;
	int	b;

	if (top - stacks->top_a <= stacks->size_tot - bottom)
	{
		while (top > stacks->top_a)
		{
			rotate_a(&(*stacks), 1);
			top--;
		}
	}
	else
	{
		while (bottom < stacks->size_tot)
		{
			re_rotate_a(&(*stacks), 1);
			bottom++;
		}
	}
}

void	ft_order_b(t_stack *stacks)
{
	int	previous;

	if (stacks->size_b <= 1)
		return ;
	previous = ft_previous_b(*(&stacks), stacks->st_a[stacks->top_a]);
	if (previous == (stacks->top_b))
		return ;
	else if (previous <= (stacks->top_b + (stacks->size_b / 2)))
	{
		while (previous > stacks->top_b)
		{
			rotate_b(&(*stacks), 1);
			previous--;
		}
	}
	else
	{
		while (previous < stacks->size_tot)
		{
			re_rotate_b(&(*stacks), 1);
			previous++;
		}
	}
}

void	ft_push_back(t_stack *stacks)
{
	int	i;
	int	first;

	first = ft_first_b(*(&stacks));
	if (first != (stacks->size_tot - 1))
	{
		if (first <= (stacks->size_b / 2))
		{
			while (first-- >= stacks->top_b)
				rotate_b(&(*stacks), 1);
		}
		else
		{
			while (first++ < stacks->size_tot - 1)
				re_rotate_b(&(*stacks), 1);
		}
	}
	i = stacks->size_b;
	while (stacks->size_b > 0)
	{
		i = stacks->size_b;
		push_a(*(&stacks), 1);
	}	
}

void	ft_chunk_algo(t_stack *stacks, int max_chunks)
{
	int	top;
	int	bottom;
	int	nbr_chu;

	nbr_chu = 1;
	while (nbr_chu <= max_chunks)
	{
		top = ft_top_chunk(&(*stacks), nbr_chu, max_chunks);
		bottom = ft_bottom_chunk(&(*stacks), nbr_chu, max_chunks);
		if (top == -1 && bottom == -1)
			nbr_chu++;
		else
		{
			ft_ra_or_rra(top, bottom, max_chunks, *(&stacks));
			ft_order_b(*(&stacks));
			push_b(*(&stacks), 1);
		}
		if (stacks->size_a == 0)
		{
			ft_push_back(*(&stacks));
			nbr_chu++;
		}
	}
}
