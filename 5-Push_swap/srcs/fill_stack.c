/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 10:07:15 by ebodart           #+#    #+#             */
/*   Updated: 2021/07/27 11:21:37 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_neg_in_pos(t_stack *stacks, int first_a)
{
	int	i;
	int	first;

	i = 0;
	first = stacks->st_a[first_a];
	while (i < stacks->size_tot)
	{
		stacks->st_a[i] = stacks->st_a[i] - first;
		i++;
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

void	ft_fill_size_top(t_stack *stacks, int argc)
{
	stacks->size_tot = argc - 1;
	stacks->size_a = argc - 1;
	stacks->size_b = 0;
	stacks->top_a = 0;
	stacks->top_b = argc - 1;
	ft_check_sorted(&(*stacks));
}

//top = dernier index où il y a un chiffre en haut de la stack
void	ft_fill_stack(t_stack *stacks, char **argv, int argc)
{
	int		i;
	int		s;
	long	value;
	int		first_a;

	stacks->st_a = malloc(sizeof(int) * argc);
	stacks->st_b = ft_calloc(argc, sizeof(int));
	if (!stacks->st_a || !stacks->st_b)
		ft_free_exit_error(&(*stacks));
	i = 1;
	s = 0;
	while (i < argc)
	{
		value = ft_atoi(argv[i], &(*stacks));
		if (value > INT_MAX || value < INT_MIN)
			ft_free_exit_error(&(*stacks));
		ft_check_duplicate(&(*stacks), s, value);
		stacks->st_a[s] = (int)value;
		i++;
		s++;
	}
	ft_fill_size_top(&(*stacks), argc);
	first_a = ft_first_a(&(*stacks));
	if (stacks->st_a[first_a] < 0)
		ft_neg_in_pos(&(*stacks), first_a);
}
