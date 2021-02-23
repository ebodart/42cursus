/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 17:41:46 by ebodart           #+#    #+#             */
/*   Updated: 2021/02/23 22:50:20 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*
** Sert à lire une ligne de la taille du buffer
*/

int		read_line(char *keep, int fd)
{
	int ret_read;
	int i;

	i = 0;
	if ((ret_read = read(fd, keep, BUFFER_SIZE)) == -1)
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

int		fill_line(char **line, int size, char *keep, int ret_read)
{
	int i;

	if (!(*line = malloc(sizeof(char) * (size + 1))))
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
** Dès que size est trouvé, on va dans la fonction fill_line pour
** mettre dans line.
*/

int		size_line(char **line, char *keep, int ret_read)
{
	int			i;
	int			size;

	i = 0;
	size = BUFFER_SIZE;
	if (ret_read == 0)
		size = 0;
	if (ret_read >= 1)
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
	if (!(new_line = malloc(sizeof(char) * (len_tmp + len_line + 1))))
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

int		get_next_line(int fd, char **line)
{
	static char	keep[MAX_FILE][BUFFER_SIZE + 1];
	int			ret_read;
	char		*tmp;
	int			i;

	i = 0;
	if (!line || (*line = NULL) || BUFFER_SIZE < 1 || fd < 0 || fd > MAX_FILE)
		return (-1);
	if (*keep[fd])
		ret_read = size_line(line, keep[fd], 1);
	else if ((ret_read = read_line(keep[fd], fd)) >= 0)
		ret_read = size_line(line, keep[fd], ret_read);
	while (ret_read > 1)
	{
		if ((ret_read = read_line(keep[fd], fd)) > 0)
		{
			tmp = *line;
			size_line(line, keep[fd], ret_read);
			if (!(*line = join_keep_line(tmp, *line, i)))
				return (-1);
		}
		if (ret_read == 0)
			keep[fd][ret_read] = '\0';
	}
	return (ret_read);
}
