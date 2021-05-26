/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_pointeur.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 18:12:36 by ebodart           #+#    #+#             */
/*   Updated: 2021/05/25 20:41:10 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_check_arg_ptr(va_list ap, t_int *print)
{
	unsigned long	nbr;
	char			*str;

	nbr = (unsigned long)va_arg(ap, void *);
	print->type = 2;
	if (print->zero > 0 && print->width > 0 && print->prec > 0)
		print->zero = 0;
	if (!nbr)
		str = "(nil)";
	else
		str = ft_int_in_hexa(nbr, "0123456789abcdef", &(*print));
	if (!str)
		str = "(nil)";
	return (str);
}

void	ft_conv_pointeur(va_list ap, t_int *print)
{
	char	*str;

	str = ft_check_arg_ptr(ap, &(*print));
	if (print->error == 1)
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
