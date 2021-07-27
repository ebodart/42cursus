/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 18:20:14 by ebodart           #+#    #+#             */
/*   Updated: 2021/07/26 23:23:49 by ebodart          ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_stack	stacks;

	if (argc == 2)
		exit(EXIT_SUCCESS);
	else if (argc > 1)
	{
		ft_fill_stack(&stacks, argv, argc);
		if (argc <= 6)
			ft_small_algo(&stacks);
		else
			ft_big_algo(&stacks);
	}
	else
		ft_exit_error();
	ft_free_exit_success(&stacks);
}
