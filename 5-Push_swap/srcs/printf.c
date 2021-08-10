/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 10:09:05 by ebodart           #+#    #+#             */
/*   Updated: 2021/08/07 12:13:03 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_printf_st_ab(t_stack *stacks)
{
	int	i;

	i = 0;
	while (i < stacks->size_tot)
	{
		printf("stack A %i = %i\n", i, stacks->st_a[i]);
		i++;
	}
	printf("\n");
	i = 0;
	while (i < stacks->size_tot)
	{
		printf("stack B %i = %i\n", i, stacks->st_b[i]);
		i++;
	}
	printf("\n");
}

void	ft_printf_stacks_info(t_stack *stacks)
{
	printf("\n");
	printf("size_tot = %i\n", stacks->size_tot);
	printf("size_a = %i\n", stacks->size_a);
	printf("size_b = %i\n", stacks->size_b);
	printf("top_a = %i\n", stacks->top_a);
	printf("top_b = %i\n\n", stacks->top_b);
}

void	ft_printf(t_stack *stacks)
{
	ft_printf_st_ab(&(*stacks));
	ft_printf_stacks_info(&(*stacks));
	//swap_a(&(*stacks));
	ft_printf_st_ab(&(*stacks));
	//push_b(&(*stacks));
	ft_printf_st_ab(&(*stacks));
	//push_b(&(*stacks));
	ft_printf_st_ab(&(*stacks));
	//push_b(&(*stacks));
	ft_printf_st_ab(&(*stacks));
	//rotate_a(&(*stacks));
	//ft_print_st_ab(&(*stacks));
	//rotate_b(&(*stacks));
	//ft_print_st_ab(&(*stacks));
	//rotate(&(*stacks));
	//ft_printf_st_ab(&(*stacks));
	//re_rotate_a(&(*stacks));
	//ft_print_st_ab(&(*stacks));
	//re_rotate_b(&(*stacks));
	//ft_print_st_ab(&(*stacks));
	//ft_printf_stacks_info(&(*stacks));
	//re_rotate(&(*stacks));
	ft_printf_st_ab(&(*stacks));
	ft_printf_stacks_info(&(*stacks));
	//swap_a(&(*stacks));
	ft_printf_st_ab(&(*stacks));
	//push_a(&(*stacks));
	ft_printf_st_ab(&(*stacks));
	//push_a(&(*stacks));
	ft_printf_st_ab(&(*stacks));
	//push_a(&(*stacks));
	ft_printf_st_ab(&(*stacks));
}
