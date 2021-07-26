/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 18:35:17 by ebodart           #+#    #+#             */
/*   Updated: 2021/07/26 17:34:50 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_bits_in_last(int nbr)
{
	int			transf;
    char        *base;
    int         i;

    i = 1;
    while (nbr >= 2)
    {
        nbr = nbr / 2;
        i++;
    }
	return (i);
}

void    ft_big_algo(t_stack *stacks)
{
    int last;
    int nbr_bits;
    int b;
    int i;

    b = 0;
    last = ft_last_a(&(*stacks));
    nbr_bits = ft_bits_in_last(stacks->st_a[last]);
    while (b < nbr_bits)
    {
        i = stacks->top_a;
        while (i < stacks->size_tot)
        {
            if ((stacks->st_a[stacks->top_a]>>b)&1 == 1)
                rotate_a(&(*stacks));
            else
                push_b(&(*stacks));
            i++;
        }
        i = stacks->top_b;
        while (i < stacks->size_tot)
        {
            push_a(&(*stacks));
            i++;
        }
        b++;
    }
}