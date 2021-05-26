/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_uninteger.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 16:12:09 by ebodart           #+#    #+#             */
/*   Updated: 2021/05/26 20:56:02 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_check_arg_unint(va_list ap, t_int *print)
{
	unsigned int		nbr;
	char				*str;

	nbr = va_arg(ap, unsigned int);
	print->type = 3;
	if (print->error == 6 || print->prec > 0 || print->error == 2
		|| (print->zero > 0 && print->minus > 0))
		print->zero = 0;
	if (print->width < 0)
	{
		print->width *= -1;
		print->minus = 1;
	}
	if (nbr == 0 && (print->error == 2 || print->error == 9))
	{
		str = " ";
		print->error = 5;
		if (print->width > 0)
			print->error = 7;
	}
	else
		str = ft_unitoa(nbr);
	return (str);
}

void	ft_conv_uninteger(va_list ap, t_int *print)
{
	char	*str;

	str = ft_check_arg_unint(ap, &(*print));
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
