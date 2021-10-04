/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 22:03:53 by ebodart           #+#    #+#             */
/*   Updated: 2021/05/19 21:50:55 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i_1;
	size_t	i_2;
	char	*new;

	i_1 = 0;
	i_2 = 0;
	if (!s1 || !s2)
		return (NULL);
	new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (NULL);
	while (s1[i_1])
	{
		new[i_1] = s1[i_1];
		i_1++;
	}
	while (s2[i_2])
	{
		new[i_1] = s2[i_2];
		i_1++;
		i_2++;
	}
	new[i_1] = '\0';
	return (new);
}
