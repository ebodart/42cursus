/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:55:25 by ebodart           #+#    #+#             */
/*   Updated: 2020/11/20 22:09:59 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char			us_c;
	size_t					i;
	unsigned char			*ptr_dst;
	unsigned char			*ptr_src;

	us_c = (unsigned char)c;
	ptr_dst = (unsigned char *)dst;
	ptr_src = (unsigned char *)src;
	i = 0;
	if ((src == NULL) && (dst == NULL))
		return (NULL);
	while (i < n)
	{
		ptr_dst[i] = ptr_src[i];
		i++;
		if (ptr_src[i - 1] == us_c)
			return ((void *)&ptr_dst[i]);
	}
	return (NULL);
}
