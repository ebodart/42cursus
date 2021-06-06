/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_in_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 18:01:58 by ebodart           #+#    #+#             */
/*   Updated: 2021/06/05 11:49:10 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len_int(unsigned int n, int len_int)
{
	int	result;

	while (n >= 10)
	{
		result = n % 10;
		n = (n - result) / 10;
		len_int++;
	}
	len_int++;
	return (len_int);
}

char	*ft_intchar(unsigned int n, int len_int, int signe)
{
	char	*str;
	int		result;

	str = malloc(sizeof(char) * (len_int + 1));
	if (!str)
		return (NULL);
	str[len_int] = '\0';
	len_int--;
	while (n >= 10)
	{
		result = n % 10;
		n = (n - result) / 10;
		str[len_int] = result + '0';
		len_int--;
	}
	str[len_int] = n + '0';
	if (signe == -1)
		str[--len_int] = '-';
	return (str);
}

char	*ft_unitoa(unsigned int n)
{
	int	len_int;
	int	signe;

	signe = 0;
	len_int = 0;
	len_int = ft_len_int(n, len_int);
	return (ft_intchar(n, len_int, signe));
}

char	*ft_itoa(int n)
{
	int				signe;
	int				len_int;
	unsigned int	pos;

	len_int = 0;
	signe = 1;
	if (n < 0)
	{
		signe = -1;
		pos = (unsigned int) -n;
		len_int++;
	}
	else
		pos = n;
	len_int = ft_len_int(pos, len_int);
	return (ft_intchar(pos, len_int, signe));
}
