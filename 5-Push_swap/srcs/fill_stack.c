/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 10:07:15 by ebodart           #+#    #+#             */
/*   Updated: 2021/09/05 22:21:00 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

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

void	ft_fill_size_top(t_stack *stacks, int nbr_args)
{
	int		first_a;

	if (nbr_args - 1 == 1 && stacks->checker == 0)
		ft_free_exit_success(&(*stacks));
	stacks->size_tot = nbr_args - 1;
	stacks->size_a = nbr_args - 1;
	stacks->size_b = 0;
	stacks->top_a = 0;
	stacks->top_b = nbr_args - 1;
	if (stacks->checker == 0)
		ft_check_sorted(&(*stacks));
	first_a = ft_first_a(&(*stacks));
	if (stacks->st_a[first_a] < 0)
		ft_neg_in_pos(&(*stacks), first_a);
	ft_nbr_suite(*(&stacks), first_a);
}

void	ft_free_args(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i++]);
	}
	free(tab);
}

void	ft_fill_stack(t_stack *stacks, char **argv, int argc, int index)
{
	int		i;
	int		value;
	char	**args;
	int		a;
	int		start;

	i = 1;
	while (i < argc)
	{
		a = 0;
		while (argv[i][a])
		{
			while (argv[i][a] == ' ' && argv[i][a] != '\0')
				a++;
			start = a;
			while (argv[i][a] != ' ' && argv[i][a] != '\0')
				a++;
			value = ft_args_in_int(start, a, argv[i], &(*stacks));
			ft_check_duplicate(&(*stacks), index, value);
			stacks->st_a[index++] = (int)value;
		}
		i++;
		if (i == argc)
			ft_fill_size_top(&(*stacks), index + 1);
	}
}
