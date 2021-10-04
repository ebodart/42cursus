/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 22:56:21 by ebodart           #+#    #+#             */
/*   Updated: 2021/10/03 18:44:07 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;

	mem = malloc(size * nmemb);
	if (!mem)
		return (NULL);
	ft_memset(mem, 0, (size * nmemb));
	return (mem);
}

int	ft_check_number(int j, const char *nptr, t_stack *stacks)
{
	if (nptr[j] >= '0' && nptr[j] <= '9')
	{
		while (nptr[j] >= '0' && nptr[j] <= '9')
			j++;
		if ((nptr[j] < '0' || nptr[j] > '9') && (nptr[j] != '\0'))
		{
			free((void *)nptr);
			ft_free_exit_error(&(*stacks));
		}
	}
	else
	{
		free((void *)nptr);
		ft_free_exit_error(&(*stacks));
	}
	return (j);
}

long	ft_result(int i, const char *nptr, int signe, t_stack *stacks)
{
	long	result;
	int		j;

	j = i;
	result = 0;
	j = ft_check_number(j, nptr, &(*stacks));
	j = j - i;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = (result * 10) + (nptr[i] - '0');
		if ((signe == 1 && result > INT_MAX)
			|| (signe == -1 && - result < INT_MIN))
		{
			free((void *)nptr);
			ft_free_exit_error(&(*stacks));
		}
		i++;
	}
	return (result);
}

long	ft_atoi(const char *nptr, t_stack *stacks)
{
	int		i;
	int		signe;
	long	result;

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
	result = ft_result(i, nptr, signe, &(*stacks));
	return ((result * signe));
}
