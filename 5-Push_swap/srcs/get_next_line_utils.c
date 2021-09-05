/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 10:22:44 by ebodart           #+#    #+#             */
/*   Updated: 2021/08/15 10:39:43 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

int	ret_read_start(char *keep, int fd, char **line)
{
	int	ret_read;

	if (*keep)
		ret_read = size_line(line, keep, 1);
	else
	{
		ret_read = read_line(keep, fd);
		if (ret_read >= 0)
			ret_read = size_line(line, keep, ret_read);
	}
	return (ret_read);
}
