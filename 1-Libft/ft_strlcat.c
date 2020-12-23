/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 17:11:23 by ebodart           #+#    #+#             */
/*   Updated: 2020/12/03 23:25:25 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	count_dst;
	size_t	count_src;

	i = 0;
	count_dst = ft_strlen(dst);
	count_src = ft_strlen(src);
	while ((i < dstsize - count_dst - 1) && (dstsize > count_dst) && src[i])
	{
		dst[count_dst + i] = src[i];
		i++;
	}
	dst[count_dst + i] = '\0';
	if (dstsize <= count_dst)
		count_dst = dstsize;
	return (count_dst + count_src);
}
