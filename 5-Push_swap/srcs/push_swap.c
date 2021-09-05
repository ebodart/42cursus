/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 18:20:14 by ebodart           #+#    #+#             */
/*   Updated: 2021/09/05 22:22:33 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stacks;
	int		count;
	int		index;

	stacks.checker = 0;
	if (argc > 1)
	{
		index = 0;
		ft_calloc_args(&stacks, argc, argv);
		ft_fill_stack(&stacks,
			argv, argc, index);
		if (stacks.size_tot <= 5)
			ft_small_algo(&stacks);
		else if (stacks.size_tot <= 100)
			ft_chunk_algo(&stacks, 5);
		else
			//ft_chunk_algo(&stacks, 11);
			ft_big_algo(&stacks);
	}
	else
		exit(EXIT_SUCCESS);
	ft_free_exit_success(&stacks);
	return (0);
}
