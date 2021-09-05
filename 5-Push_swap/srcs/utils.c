/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 22:56:21 by ebodart           #+#    #+#             */
/*   Updated: 2021/08/15 11:51:04 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_putendl(char *s, int fd)
{
	int	i;

	i = 0;
	while (!(!s) && s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}

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

long	ft_result(int i, const char *nptr, int signe, t_stack *stacks)
{
	long	result;
	int		j;

	j = i;
	result = 0;
	if (nptr[j] >= '0' && nptr[j] <= '9')
	{
		while (nptr[j] >= '0' && nptr[j] <= '9')
			j++;
		if ((nptr[j] < '0' || nptr[j] > '9') && (nptr[j] != '\0'))
			ft_free_exit_error(&(*stacks));
	}
	else
		ft_free_exit_error(&(*stacks));
	j = j - i;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = (result * 10) + (nptr[i] - '0');
		if ((signe == 1 && result > INT_MAX)
			|| (signe == -1 && - result < INT_MIN))
			ft_free_exit_error(&(*stacks));
		i++;
	}
	return (result);
}

long	ft_atoi(const char *nptr, t_stack *stacks)
{
	int		i;
	int		signe;
	int		j;
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
