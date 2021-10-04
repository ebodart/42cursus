/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 15:21:08 by ebodart           #+#    #+#             */
/*   Updated: 2021/05/19 12:25:07 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_result(int i, const char *nptr, int j, int signe)
{
	unsigned long long	result;

	result = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = (result * 10) + (nptr[i] - '0');
		if ((result >= LONG_MAX || j > 19) && signe == 1)
			return (-1);
		else if ((result >= LONG_MAX || j > 19) && signe == -1)
			return (0);
		i++;
	}
	return ((int)result);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	signe;
	int	j;
	int	result;

	i = 0;
	while (nptr[i] == ' ' || nptr[i] == '\f' || nptr[i] == '\n'
		|| nptr[i] == '\r' || nptr[i] == '\t' || nptr[i] == '\v')
		i++;
	signe = 1;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i++] == '-')
			signe = -1;
	}
	j = i;
	while (nptr[j] >= '0' && nptr[j] <= '9')
		j++;
	j = j - i;
	result = ft_result(i, nptr, j, signe);
	return ((result * signe));
}
