/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 18:20:14 by ebodart           #+#    #+#             */
/*   Updated: 2021/08/10 22:23:28 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
		exit(EXIT_SUCCESS);
	ft_free_exit_success(&stacks);
	return (0);
}
