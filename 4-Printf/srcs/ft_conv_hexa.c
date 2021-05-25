/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 21:03:41 by ebodart           #+#    #+#             */
/*   Updated: 2021/05/25 19:45:38 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_check_arg_hexa(va_list ap, t_int *print)
{
	int unsigned	nbr;
	char			*str;

	nbr = va_arg(ap, unsigned int);
	if (print->zero > 0 && print->width > 0 && print->prec > 0)
		print->zero = 0;
	if (print->type == 4)
		str = ft_int_in_hexa(nbr, "0123456789abcdef", &(*print));
	else
		str = ft_int_in_hexa(nbr, "0123456789ABCDEF", &(*print));
	if (!str)
		str = "(null)";
	return (str);
}

void	ft_conv_hexa(va_list ap, t_int *print)
{
	char	*str;

	str = ft_check_arg_hexa(ap, &(*print));
	if (print->error != 0 && print->error != 2)
		return ;
	print->len = ft_strlen(str);
	if (print->minus > 0)
	{
		ft_putnbr(str, &(*print));
		ft_write_minus(&(*print));
	}
	else if (print->zero > 0)
	{
		ft_write_zero(&(*print));
		ft_putnbr(str, &(*print));
	}
	else if (print->width > 0)
	{
		ft_write_width(&(*print));
		ft_putnbr(str, &(*print));
	}
	else
		ft_putnbr(str, &(*print));
}
