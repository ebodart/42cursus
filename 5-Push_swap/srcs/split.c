/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 10:35:59 by ebodart           #+#    #+#             */
/*   Updated: 2021/08/18 21:08:25 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	i = 0;
	s_len = ft_strlen(s);
	if (start >= s_len)
		len = 0;
	else if (len + start > s_len)
		len = (s_len - start);
	new = malloc(sizeof(char) * (len + 1));
	if (!(new))
		return (NULL);
	if (start < s_len)
	{
		while (i < len)
			new[i++] = s[start++];
	}
	new[i] = '\0';
	return (new);
}

static int	free_tab(char **tab, int i)
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

static int	ft_putmot(char const *s, char c, size_t nbr_mots, char **tab)
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
		tab[i_mot] = ft_substr(s, start, (len - start + 1));
		if (!(tab[i_mot]))
			return (free_tab(tab, i_mot));
		start = len + 1;
		i_mot++;
	}
	tab[i_mot] = 0;
	return (1);
}

static size_t	ft_nbr_mots(char const *s, char c)
{
	size_t	i;
	size_t	count;

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

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	nbr_mots;

	if (!s)
		return (NULL);
	nbr_mots = ft_nbr_mots(s, c);
	tab = malloc(sizeof(char *) * (nbr_mots + 1));
	if (!(tab))
		return (NULL);
	if (!(ft_putmot(s, c, nbr_mots, tab)))
		return (NULL);
	return (tab);
}
