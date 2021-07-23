/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 18:20:14 by ebodart           #+#    #+#             */
/*   Updated: 2021/07/23 09:52:31 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//top = dernier index où il y a un chiffre en haut de la stack

void	ft_fill_stack(t_stack *stacks, char **argv, int argc)
{
	int	i;
	int	s;
	int	value;

	stacks->stack_a = malloc(sizeof(int) * argc);
	stacks->stack_b = ft_calloc(argc, sizeof(int));
	if (!stacks->stack_a || !stacks->stack_b)
		ft_free_exit_error(&(*stacks));
	i = 1;
	s = 0;
	while (i < argc)
	{
		value = ft_atoi(argv[i]);
		stacks->stack_a[s] = value;
		i++;
		s++;
	}
	stacks->size_total = argc - 1;
	stacks->size_a = argc - 1;
	stacks->size_b = 0;
	stacks->top_a = 0;
	stacks->top_b = argc - 1;
}

void	ft_print_stack(t_stack *stacks)
{
	int	i;

	i = 0;
	while (i < stacks->size_total)
	{
		printf("stack A %i = %i\n", i, stacks->stack_a[i]);
		i++;
	}
	printf("\n");
	i = 0;
	while (i < stacks->size_total)
	{
		printf("stack B %i = %i\n", i, stacks->stack_b[i]);
		i++;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_stack	stacks;

	if (argc > 1)
	{
		ft_fill_stack(&stacks, argv, argc);
		ft_print_stack(&stacks);
	}
	else
		ft_exit_error();
	printf("swap_a\n");
	swap_a(&stacks);
	ft_print_stack(&stacks);
	printf("push_b1\n");
	push_b(&stacks);
	ft_print_stack(&stacks);
	printf("push_b2\n");
	push_b(&stacks);
	ft_print_stack(&stacks);
	printf("push_b3\n");
	push_b(&stacks);
	ft_print_stack(&stacks);
	//push_a(&stacks);
	//ft_print_stack(&stacks);
	printf("rotate_a\n");
	rotate_a(&stacks);
	ft_print_stack(&stacks);
	printf("rotate_b\n");
	rotate_b(&stacks);
	ft_print_stack(&stacks);
	printf("re_rotate_a\n");
	re_rotate_a(&stacks);
	ft_print_stack(&stacks);
	printf("re_rotate_b\n");
	re_rotate_b(&stacks);
	ft_print_stack(&stacks);
	printf("\n");
	printf("size_tot = %i\n", stacks.size_total);
	printf("size_a = %i\n", stacks.size_a);
	printf("size_b = %i\n", stacks.size_b);
	printf("top_a = %i\n", stacks.top_a);
	printf("top_b = %i\n\n", stacks.top_b);
	printf("swap_a\n");
	swap_a(&stacks);
	ft_print_stack(&stacks);
	printf("push_a1\n");
	push_a(&stacks);
	ft_print_stack(&stacks);
	printf("push_a2\n");
	push_a(&stacks);
	ft_print_stack(&stacks);
	printf("push_a3\n");
	push_a(&stacks);
	ft_print_stack(&stacks);
	ft_free_exit_success(&stacks);
}
