/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 16:42:24 by ebodart           #+#    #+#             */
/*   Updated: 2020/11/21 16:54:39 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char *new;

	if (!(new = malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	ft_strlcpy(new, s, (ft_strlen(s) + 1));
	return (new);
}
