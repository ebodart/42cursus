/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 17:41:46 by ebodart           #+#    #+#             */
/*   Updated: 2021/08/12 18:21:09 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

/*
** Fonction qui sert à remplir line par ce qu'on a trouvé dans keep
** en tenant compte de la taille à allouer gr^ace à la fonction fill_line
*/

int	fill_line(char **line, int size, char *keep, int ret_read)
{
	int	i;

	*line = malloc(sizeof(char) * (size + 1));
	if (!(*line))
		return (-1);
	i = 0;
	while (i < size)
	{
		(*line)[i] = keep[i];
		i++;
	}
	(*line)[i] = '\0';
	if (size != BUFFER_SIZE)
	{
		init_keep(keep, i);
		return (ret_read);
	}
	return (2);
}

/*
** Fonction qui sert à calculer la taille pour malloc line.
** On va calculer size qui correspond à l'endroit ou se trouve le /n ou /0.
** Dès que size est trouvé, on va dans la fonction fill_line
** pour mettre dans line.
*/

int	size_line(char **line, char *keep, int ret_read)
{
	int	i;
	int	size;

	i = 0;
	size = BUFFER_SIZE;
	if (ret_read == 0)
		size = 0;
	if (ret_read == 1)
	{
		while (size == BUFFER_SIZE)
		{
			if (keep[i] == '\n' || keep[i] == '\0')
			{
				size = i;
				if (keep[i] == '\0')
					ret_read = 2;
			}
			i++;
		}
	}
	return (fill_line(line, size, keep, ret_read));
}

/*
** Sert à updater line ce qu'il y avait avant dans line et ce qu'on
** vient de trouver en lisant avec keep
*/

char	*join_keep_line(char *tmp, char *line, int i)
{
	char	*new_line;
	int		len_tmp;
	int		len_line;

	len_tmp = ft_strlen(tmp);
	len_line = ft_strlen(line);
	new_line = malloc(sizeof(char) * (len_tmp + len_line + 1));
	if (!(new_line))
	{
		free(tmp);
		free(line);
		return (NULL);
	}
	while (i < len_tmp)
	{
		new_line[i] = tmp[i];
		i++;
	}
	i = 0;
	while (i < len_line)
		new_line[len_tmp++] = line[i++];
	new_line[len_tmp] = '\0';
	free(tmp);
	free(line);
	return (new_line);
}

int	get_next_line(int fd, char **line)
{
	static char	keep[BUFFER_SIZE + 1];
	int			ret_read;
	char		*tmp;
	int			i;

	i = 0;
	if (!line || BUFFER_SIZE < 1 || fd < 0)
		return (-1);
	*line = NULL;
	ret_read = ret_read_start(keep, fd, line);
	while (ret_read > 1)
	{
		ret_read = read_line(keep, fd);
		if (ret_read > 0)
		{
			tmp = *line;
			size_line(line, keep, ret_read);
			*line = join_keep_line(tmp, *line, i);
			if (!(*line))
				return (-1);
		}
	}
	if (ret_read == 0)
		keep[ret_read] = '\0';
	return (ret_read);
}
