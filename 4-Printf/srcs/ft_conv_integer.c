/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_integer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:38:12 by ebodart           #+#    #+#             */
/*   Updated: 2021/05/24 18:06:53 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_check_arg_int(va_list ap, t_int *print)
{
	int		nbr;
	char	*str;

	nbr = va_arg(ap, int);
	print->type = 2;
	if (nbr < 0)
		print->type = -2;
	if (nbr < 0 && print->prec > 0 )
		print->prec += 1;
	if (print->zero > 0 && print->width > 0 && print->prec > 0)
		print->zero = 0;
	str = ft_itoa(nbr);
	if (!str)
		str = "(null)";
	return (str);
}

void	ft_putnbr(char *str, t_int *print)
{
	int	i;
	int	l;
	int	z;

	i = 0;
	l = 0;
	z = print->len;
	if (print->type == -2 && print->zero <= 0)
		ft_putchar(str[i++], &(*print));
	if (print->type == -2 && print->zero > 0)
		i++;
	if (print->type == -2)
		z--;
	if (print->prec > 0 && print->len < print->prec)
		l = print->prec - print->len;
	if (print->error == 2)
		z = 0;
	while (l > 0)
	{
		ft_putchar('0', &(*print));
		l--;
	}
	while (z-- > 0)
		ft_putchar(str[i++], &(*print));
}

void	ft_conv_integer(va_list ap, t_int *print)
{
	char	*str;

	str = ft_check_arg_int(ap, &(*print));
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
