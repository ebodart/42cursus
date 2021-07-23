/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 18:20:14 by ebodart           #+#    #+#             */
/*   Updated: 2021/07/23 14:07:48 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stacks;

	if (argc > 1)
	{
		ft_fill_stack(&stacks, argv, argc);
	}
	else
		ft_exit_error();
	ft_small_algo(&stacks);
	//ft_printf(&stacks);
	ft_free_exit_success(&stacks);
}
