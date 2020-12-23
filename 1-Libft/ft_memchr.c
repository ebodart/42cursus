/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 12:52:25 by ebodart           #+#    #+#             */
/*   Updated: 2020/11/20 22:09:45 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	us_c;
	size_t			i;
	unsigned char	*ptr_s;

	ptr_s = (unsigned char *)s;
	us_c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (ptr_s[i] == us_c)
			return ((void *)&ptr_s[i]);
		i++;
	}
	return (NULL);
}
