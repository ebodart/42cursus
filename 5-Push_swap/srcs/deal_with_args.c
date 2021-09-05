/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_with_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 19:01:43 by ebodart           #+#    #+#             */
/*   Updated: 2021/09/05 22:17:48 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_count_args(int argc, char **argv)
{
	int	count;
	int	i;
	int	a;

	i = 1;
	count = 0;
	while (i < argc)
	{
		a = 0;
		while (argv[i][a])
		{
			while (argv[i][a] == ' ' && argv[i][a] != '\0')
				a++;
			count++;
			while (argv[i][a] != ' ' && argv[i][a] != '\0')
				a++;
		}
		i++;
		if (i == argc)
			return (count);
	}
	return (count);
}

void	ft_calloc_args(t_stack *stacks, int argc, char **argv)
{
	int		count;

	count = ft_count_args(argc, argv);
	stacks->st_a = ft_calloc(count + 1, sizeof(int));
	stacks->st_b = ft_calloc(count + 1, sizeof(int));
	if (!stacks->st_a || !stacks->st_b)
		ft_free_exit_error(&(*stacks));
	return ;
}

int	ft_args_in_int(int start, int end, char *argv, t_stack *stacks)
{
	char	*word;
	int		a;
	int		value;

	word = malloc(sizeof(char) * (end - start + 1));
	if (!(word))
		ft_free_exit_error(&(*stacks));
	a = 0;
	while (start < end)
	{
		word[a] = argv[start];
		start++;
		a++;
	}
	word[a] = '\0';
	value = ft_atoi(word, &(*stacks));
	free(word);
	return ((int)value);
}
