/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 18:42:09 by ebodart           #+#    #+#             */
/*   Updated: 2021/10/04 09:50:13 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	ordre;

	i = 0;
	while (s1[i] == s2[i])
	{
		if ((s1[i] == '\0') && (s2[i] == '\0'))
			return (0);
		i++;
	}
	ordre = s1[i] - s2[i];
	return (ordre);
}

void	ft_ok_or_ko(t_stack *stacks)
{
	int	i;

	i = 0;
	if (stacks->size_tot == 1)
	{
		if (stacks->size_b == 0)
			ft_free_exit_ok(&(*stacks));
		else
			ft_free_exit_ko(&(*stacks));
	}
	while (stacks->st_a[i] < stacks->st_a[i + 1])
	{
		i++;
		if (i == stacks->size_tot - 1 && stacks->size_b == 0)
		{
			ft_free_exit_ok(&(*stacks));
		}
	}
	ft_free_exit_ko(&(*stacks));
}

void	ft_operations(char *line, t_stack *stacks)
{
	if (ft_strcmp(line, "pa") == 0)
		push_a(&(*stacks), 0);
	else if (ft_strcmp(line, "pb") == 0)
		push_b(&(*stacks), 0);
	else if (ft_strcmp(line, "sa") == 0)
		swap_a(&(*stacks), 0);
	else if (ft_strcmp(line, "sb") == 0)
		swap_b(&(*stacks), 0);
	else if (ft_strcmp(line, "ss") == 0)
		swap_ab(&(*stacks), 0);
	else if (ft_strcmp(line, "ra") == 0)
		rotate_a(&(*stacks), 0);
	else if (ft_strcmp(line, "rb") == 0)
		rotate_b(&(*stacks), 0);
	else if (ft_strcmp(line, "rr") == 0)
		rotate(&(*stacks), 0);
	else if (ft_strcmp(line, "rra") == 0)
		re_rotate_a(&(*stacks), 0);
	else if (ft_strcmp(line, "rrb") == 0)
		re_rotate_b(&(*stacks), 0);
	else if (ft_strcmp(line, "rrr") == 0)
		re_rotate(&(*stacks), 0);
	else
		ft_free_line_exit_error(&(*stacks), line);
}

void	ft_fill_args(t_stack *stacks, int argc, char **argv)
{
	int	index;

	index = 0;
	stacks->checker = 1;
	ft_calloc_args(*(&stacks), argc, argv);
	ft_fill_stack(*(&stacks), argv, argc, index);
	return ;
}

int	main(int argc, char **argv)
{
	t_stack	stacks;
	char	*line;
	int		ret;

	if (argc < 2)
		return (1);
	ft_fill_args(&stacks, argc, argv);
	ret = get_next_line(STDIN, &line);
	while (ret > 0)
	{
		ft_operations(line, &stacks);
		free(line);
		ret = get_next_line(STDIN, &line);
	}
	if (!(line[0] == '\0'))
	{
		free(line);
		ft_free_exit_error(&stacks);
	}
	free(line);
	if (ret < 0)
		ft_free_exit_error(&stacks);
	ft_ok_or_ko(&stacks);
	ft_free_exit_success(&stacks);
	return (0);
}
