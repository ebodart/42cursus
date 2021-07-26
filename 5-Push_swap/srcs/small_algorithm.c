/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 12:16:57 by ebodart           #+#    #+#             */
/*   Updated: 2021/07/25 18:20:34 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_three_digits(t_stack *stacks)
{
	int	first_a;
	int	second_a;
	int	last_a;

	first_a = ft_first_a(&(*stacks));
	if (stacks->st_a[first_a] == stacks->st_a[stacks->top_a])
		swap_a(&(*stacks));
	last_a = ft_last_a(&(*stacks));
	if (stacks->st_a[last_a] == stacks->st_a[stacks->top_a])
		rotate_a(&(*stacks));
	ft_check_sorted(&(*stacks));
	last_a = ft_last_a(&(*stacks));
	first_a = ft_first_a(&(*stacks));
	if (stacks->st_a[last_a] == stacks->st_a[stacks->top_a + 2]
		&& stacks->st_a[first_a] == stacks->st_a[stacks->top_a + 1])
		swap_a(&(*stacks));
	first_a = ft_first_a(&(*stacks));
	if (stacks->st_a[first_a] == stacks->st_a[stacks->top_a + 2])
		re_rotate_a(&(*stacks));
	ft_check_sorted(&(*stacks));
}

void	ft_second_top(t_stack *stacks, int first_a, int second_a, int last_a)
{
	if (stacks->st_a[first_a] == stacks->st_a[stacks->size_tot - 1]
		|| (stacks->st_a[second_a] == stacks->st_a[stacks->size_tot - 1]))
		re_rotate_a(&(*stacks));
	else if (stacks->st_a[first_a] == stacks->st_a[stacks->top_a + 1]
		|| (stacks->st_a[second_a] == stacks->st_a[stacks->top_a + 1]))
	{
		last_a = ft_last_a(&(*stacks));
		if (stacks->st_a[last_a] == stacks->st_a[stacks->top_a])
			rotate_a(&(*stacks));
		else
			swap_a(&(*stacks));
	}
	else if (stacks->st_a[first_a] == stacks->st_a[stacks->size_tot - 2]
		|| (stacks->st_a[second_a] == stacks->st_a[stacks->size_tot - 2]))
	{
		rotate_a(&(*stacks));
		last_a = ft_last_a(&(*stacks));
		if (stacks->st_a[last_a] == stacks->st_a[stacks->top_a])
			rotate_a(&(*stacks));
		else
			swap_a(&(*stacks));
	}
}

void	ft_first_top(t_stack *stacks, int first_a, int second_a)
{
	int	first_b;
	int	last_a;

	first_a = ft_first_a(&(*stacks));
	second_a = ft_second_a(&(*stacks), first_a);
	push_b(&(*stacks));
	ft_second_top(&(*stacks), first_a, second_a, last_a);
	push_b(&(*stacks));
	ft_three_digits(&(*stacks));
	first_b = ft_first_b(&(*stacks));
	if (stacks->st_b[first_b] == stacks->st_b[stacks->top_b])
		swap_b(&(*stacks));
	push_a(&(*stacks));
	push_a(&(*stacks));
	ft_free_exit_success(&(*stacks));
}

void	ft_five_digits(t_stack *stacks)
{
	int	first_a;
	int	second_a;

	first_a = ft_first_a(&(*stacks));
	second_a = ft_second_a(&(*stacks), first_a);
	if (stacks->st_a[first_a] == stacks->st_a[stacks->top_a]
		|| (stacks->st_a[second_a] == stacks->st_a[stacks->top_a]))
		ft_first_top(&(*stacks), first_a, second_a);
	else
	{
		if (stacks->st_a[first_a] == stacks->st_a[stacks->size_tot - 1]
			|| stacks->st_a[second_a] == stacks->st_a[stacks->size_tot - 1])
			re_rotate_a(&(*stacks));
		else
		{
			rotate_a(&(*stacks));
			first_a = ft_first_a(&(*stacks));
			second_a = ft_second_a(&(*stacks), first_a);
			if (stacks->st_a[first_a] != stacks->st_a[stacks->top_a]
				&& stacks->st_a[second_a] != stacks->st_a[stacks->top_a])
				rotate_a(&(*stacks));
		}
	}
	ft_first_top(&(*stacks), first_a, second_a);
}

void	ft_small_algo(t_stack *stacks)
{
	int	first_a;
	int	second_a;
	int	last_a;

	if (stacks->size_tot <= 3)
		ft_three_digits(&(*stacks));
	else
		ft_five_digits(&(*stacks));
}
