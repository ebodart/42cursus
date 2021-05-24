/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 18:43:50 by ebodart           #+#    #+#             */
/*   Updated: 2021/05/24 21:09:33 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//type: 0 = char, 1 = str, 2 = pointeur, 3 = int, -3 = int neg, 4 = hexalow, 5 = hexaup
void	ft_init_struct(t_int *print)
{
	print->index = 0;
	print->ret = 0;
	print->len = 0;
	print->minus = 0;
	print->zero = 0;
	print->width = 0;
	print->prec = 0;
	print->error = 0;
	print->type = 0;
}

void	ft_putchar(char c, t_int *print)
{
	write(1, &c, 1);
	print->ret += 1;
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_conversion(va_list ap, t_int *print, int i, const char *format)
{
	char	c;

	c = format[i];
	if (c == 'c')
		ft_conv_char(ap, &(*print));
	if (c == 's')
		ft_conv_string(ap, &(*print));
	if (c == '%')
		ft_conv_percent(&(*print));
	if (c == 'd' || c == 'i')
		ft_conv_integer(ap, &(*print));
	if (c == 'u')
		ft_conv_uninteger(ap, &(*print));
	if (c == 'x' || c == 'X')
	{
		print->type = 4;
		if (c == 'X')
			print->type = 5;
		ft_conv_hexa(ap, &(*print));
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	t_int	print;

	ft_init_struct(&print);
	va_start(ap, format);
	while (format[print.index] != '\0')
	{
		if (format[print.index] != '%')
		{
			ft_putchar(format[print.index], &print);
		}
		else
		{
			print.index++;
			ft_fill_print(&print, format, ap);
			if (print.error != 0 && print.error != 2)
				return (0);
		}
		print.index++;
	}
	va_end(ap);
	return (print.ret);
}
