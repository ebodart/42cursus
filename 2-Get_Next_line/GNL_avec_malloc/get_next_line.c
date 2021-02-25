/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 17:41:46 by ebodart           #+#    #+#             */
/*   Updated: 2021/02/25 17:24:36 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** Fonction qui sert à remplir line par ce qu'on a trouvé dans keep
** en tenant compte de la taille à allouer gr^ace à la fonction fill_line
*/

int		fill_line(char **line, long int size, char *keep, int ret_read)
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
** Dès que size est trouvé, on va dans la fonction fill_line
** pour mettre dans line.
*/

int		size_line(char **line, char *keep, int ret_read)
{
	int			i;
	long int	size;

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

/*
** Fonction qui sert à lire les prochaines lignes
*/

int		next_line(char *keep, int fd, char **line)
{
	int		i;
	char	*tmp;
	int		ret_read;

	i = 0;
	if ((ret_read = read_line(keep, fd)) > 0)
	{
		tmp = *line;
		size_line(line, keep, ret_read);
		if (!(*line = join_keep_line(tmp, *line, i)))
		{
			free(keep);
			return (-1);
		}
	}
	return (ret_read);
}

int		get_next_line(int fd, char **line)
{
	static char	*keep;
	int			ret_read;

	ret_read = 0;
	if (!line || (*line = NULL) || BUFFER_SIZE < 1 || fd < 0)
		return (-1);
	if (keep == NULL)
		if (!(keep = ft_calloc(BUFFER_SIZE + 1, sizeof(char))))
			return (-1);
	if (*keep)
		ret_read = size_line(line, keep, 1);
	else if ((ret_read = read_line(keep, fd)) >= 0)
		ret_read = size_line(line, keep, ret_read);
	while (ret_read > 1)
		ret_read = next_line(keep, fd, line);
	if (ret_read < 1)
	{
		free(keep);
		keep = NULL;
	}
	return (ret_read);
}
