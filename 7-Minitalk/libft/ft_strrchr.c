/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 14:58:54 by ebodart           #+#    #+#             */
/*   Updated: 2021/05/19 12:35:39 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	z;

	i = 0;
	while (s[i])
		i++;
	z = i;
	if (c == '\0')
		return ((char *)&s[z]);
	while (z >= 0)
	{
		if (c == s[z])
			return ((char *)&s[z]);
		z--;
	}
	return (NULL);
}
