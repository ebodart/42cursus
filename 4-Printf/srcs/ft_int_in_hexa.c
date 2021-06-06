/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_in_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 19:08:26 by ebodart           #+#    #+#             */
/*   Updated: 2021/06/06 10:23:33 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len_int_base(unsigned long n, int len_int,
					unsigned long len_base, t_int *print)
{
	int	result;

	while (n >= len_base)
	{
		result = n % len_base;
		n = (n - result) / len_base;
		len_int++;
	}
	len_int++;
	if (print->type == 2)
		len_int = len_int + 2;
	return (len_int);
}

char	*ft_intchar_base(unsigned long n, char *base, int len_int,
							unsigned long len_base)
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
	return (str);
}

char	*ft_int_in_hexa(unsigned long n, char *base, t_int *print)
{
	int				len_int;
	unsigned long	len_base;
	char			*str;

	len_base = 0;
	while (base[len_base])
		len_base++;
	len_int = 0;
	len_int = ft_len_int_base(n, len_int, len_base, &(*print));
	str = ft_intchar_base(n, base, len_int, len_base);
	if (print->type == 2)
	{
		str[1] = 'x';
		str[0] = '0';
	}
	return (str);
}
