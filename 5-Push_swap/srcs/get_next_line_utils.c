/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 10:22:44 by ebodart           #+#    #+#             */
/*   Updated: 2021/08/10 22:24:17 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/*
** Sert à remettre ce qui suit le /n au début de la variable static
** ou bien à mettre à 0 la variable static
*/

void	init_keep(char *keep, int i)
{
	char	*tmp;
	int		j;
	char	*str;

	j = 0;
	tmp = keep;
	i++;
	while (tmp[i])
	{
		keep[j] = tmp[i];
		i++;
		j++;
	}
	if (j < i)
	{
		str = (char *)keep;
		while (j < i)
		{
			str[j] = '\0';
			j++;
		}
	}
}

/*
** Sert à lire une ligne de la taille du buffer
*/

int	read_line(char *keep, int fd)
{
	int	ret_read;
	int	i;

	i = 0;
	ret_read = read(fd, keep, BUFFER_SIZE);
	if (ret_read == -1)
		return (-1);
	else if (ret_read == 0)
	{
		keep[0] = -1;
		return (0);
	}
	else
	{
		keep[ret_read] = '\0';
		while (keep[i])
		{
			if (keep[i] == '\n')
				return (1);
			i++;
		}
		return (2);
	}
}
