/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 12:17:05 by ebodart           #+#    #+#             */
/*   Updated: 2021/05/21 11:31:02 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*ptr_dst;
	unsigned char	*ptr_src;

	i = -1;
	ptr_dst = (unsigned char *)dst;
	ptr_src = (unsigned char *)src;
	if ((src == NULL) && (dst == NULL))
		return (NULL);
	if (ptr_dst > ptr_src)
	{
		while (len > 0)
		{
			ptr_dst[len - 1] = ptr_src[len - 1];
			len--;
		}
	}
	else
	{
		while (++i < len)
			ptr_dst[i] = ptr_src[i];
	}
	return (dst);
}
