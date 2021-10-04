/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 19:41:29 by ebodart           #+#    #+#             */
/*   Updated: 2021/05/19 21:48:36 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	if (!new)
		return (NULL);
	if (start < s_len)
	{
		while (i < len)
		{
			new[i++] = s[start];
			start++;
		}
	}
	new[i] = '\0';
	return (new);
}
