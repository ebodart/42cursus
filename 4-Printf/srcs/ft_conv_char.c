/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 21:45:58 by ebodart           #+#    #+#             */
/*   Updated: 2021/05/20 18:44:51 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conv_char(va_list ap, t_int *print)
{
	char	c;

	c = va_arg(ap, int);
	print->len = 1;
	if (print->minus > 0)
	{
		ft_putchar(c, &(*print));
		ft_write_minus(&(*print));
	}
	else if (print->zero > 0)
	{
		ft_write_zero(&(*print));
		ft_putchar(c, &(*print));
	}
	else if (print->width > 0)
	{
		ft_write_width(&(*print));
		ft_putchar(c, &(*print));
	}
	else
		ft_putchar(c, &(*print));
}
