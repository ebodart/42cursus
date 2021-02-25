/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 10:22:44 by ebodart           #+#    #+#             */
/*   Updated: 2021/02/23 16:47:01 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
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
