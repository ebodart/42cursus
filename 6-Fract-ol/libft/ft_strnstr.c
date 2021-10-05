/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 14:16:07 by ebodart           #+#    #+#             */
/*   Updated: 2021/05/19 12:35:03 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	b;
	size_t	l;

	b = 0;
	if (!little[0])
		return ((char *)big);
	while (b < len && big[b])
	{
		l = 0;
		while (big[b + l] == little[l] && b + l < len && little[l])
			l++;
		if (!little[l])
			return ((char *)&big[b]);
		b++;
	}
	return (NULL);
}
