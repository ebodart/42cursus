/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 17:55:35 by ebodart           #+#    #+#             */
/*   Updated: 2020/12/03 18:45:16 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		free_tab(char **tab, int i)
{
	i--;
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
	return (0);
}

static int		ft_putmot(char const *s, char c, size_t nbr_mots, char **tab)
{
	size_t			i_mot;
	size_t			len;
	unsigned int	start;

	i_mot = 0;
	start = 0;
	while (i_mot < nbr_mots)
	{
		while (s[start] == c)
			start++;
		len = start;
		while (s[len + 1] != c && s[len + 1] != '\0')
			len++;
		if (!(tab[i_mot] = ft_substr(s, start, (len - start + 1))))
			return (free_tab(tab, i_mot));
		start = len + 1;
		i_mot++;
	}
	tab[i_mot] = 0;
	return (1);
}

static size_t	ft_nbr_mots(char const *s, char c)
{
	size_t i;
	size_t count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
		{
			i++;
			if (s[i] == '\0')
				return (count);
		}
		count++;
		while (s[i] != c)
		{
			i++;
			if (s[i] == '\0')
				return (count);
		}
	}
	return (count);
}

char			**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	nbr_mots;

	if (!s)
		return (NULL);
	nbr_mots = ft_nbr_mots(s, c);
	if (!(tab = malloc(sizeof(char*) * (nbr_mots + 1))))
		return (NULL);
	if (!(ft_putmot(s, c, nbr_mots, tab)))
		return (NULL);
	return (tab);
}
