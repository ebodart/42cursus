/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_in_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 19:08:26 by ebodart           #+#    #+#             */
/*   Updated: 2021/05/24 21:01:57 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len_int_base(unsigned int n, int len_int, unsigned int len_base)
{
	int	result;
	
	while (n >= len_base)
	{
		result = n % len_base;
		n = (n - result) / len_base;
		len_int++;
	}
	len_int++;
	return (len_int);
}

char	*ft_intchar_base(unsigned int n, int len_int, unsigned int len_base, char *base)
{
	char	*str;
	int		result;

	str = malloc(sizeof(char) * (len_int + 1));
	if (!str)
		return (NULL);
	str[len_int] = '\0';
	len_int--;
	while (n > 0)
	{
		result = n % len_base;
		str[len_int] = base[result];
		n = n / len_base;
		len_int--;
	}
	str[len_int] = base[n];
	return (str);
}

char	*ft_int_in_hexa(unsigned int n, char *base)
{
	int	len_int;
	unsigned int len_base;
	
	len_base = 0;
	while (base[len_base])
		len_base++;
	len_int = 0;
	len_int = ft_len_int_base(n, len_int, len_base);
	return (ft_intchar_base(n, len_int, len_base, base));
}
