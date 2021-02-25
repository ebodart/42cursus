/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 10:22:44 by ebodart           #+#    #+#             */
/*   Updated: 2021/02/25 17:25:44 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*
** Sert à lire une ligne de la taille du buffer
*/

int			read_line(char *keep, int fd)
{
	int ret_read;
	int i;

	i = 0;
	if ((ret_read = read(fd, keep, BUFFER_SIZE)) == -1)
		return (-1);
	else if (ret_read == 0)
		return (0);
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

size_t		ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/*
** Sert à remettre ce qui suit le /n au début de la variable static
** ou bien à mettre à 0 la variable static
*/

void		init_keep(char *keep, long int i)
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

void		*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;
	size_t	i;
	char	*str;

	if (!(mem = malloc(size * nmemb)))
		return (NULL);
	i = 0;
	str = (char *)mem;
	while (i < nmemb)
	{
		str[i] = 0;
		i++;
	}
	return (mem);
}
