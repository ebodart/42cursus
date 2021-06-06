/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 21:37:18 by ebodart           #+#    #+#             */
/*   Updated: 2021/06/06 21:46:20 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_fill_zero_minus(t_int *print, const char *format, int i)
{
	while (format[i] == '0' || format[i] == '-')
	{
		if (format[i] == '0')
		{
			print->zero = i;
			i++;
		}
		if (format[i] == '-')
		{
			print->minus = i;
			i++;
		}
	}
	return (i);
}

int	ft_fill_star(t_int *print, int i, va_list ap, int width)
{
	int	w;

	if (width == 1)
	{
		w = va_arg(ap, int);
		print->width = w;
		if (print->width == 0)
			print->error = 6;
		i++;
	}
	else
	{
		w = va_arg(ap, int);
		print->prec = w;
		if (print->prec == 0)
			print->error = 2;
		i++;
	}
	return (i);
}

//error = 6 si pas de nbr pour width
//error = 8 si width = 0
int	ft_fill_width(t_int *print, const char *format, int i, va_list ap)
{
	int	w;

	w = 0;
	if (format[i] == '*' || ((format[i] > '0') && (format[i] <= '9')))
	{
		if (format[i] == '*')
			i = ft_fill_star(&(*print), i, ap, 1);
		else
		{
			while ((format[i] >= '0') && (format[i] <= '9'))
			{
				print->width = (print->width * 10) +(format[i] - '0');
				i++;
				w++;
			}
			if (print->width == 0)
				print->error = 6;
			if (print->width == 0 && w == 0)
				print->error = 8;
		}
	}
	return (i);
}

//error = 2 si pas de nbr pour prec
//error = 9 si prec = 0
int	ft_fill_prec(t_int *print, const char *format, int i, va_list ap)
{
	int	w;

	w = 0;
	if (format[i] == '.')
	{
		i++;
		if (format[i] == '*')
			i = ft_fill_star(&(*print), i, ap, 2);
		else
		{
			while ((format[i] >= '0') && (format[i] <= '9'))
			{
				print->prec = (print->prec * 10) +(format[i] - '0');
				i++;
				w++;
			}
			if (print->prec == 0)
				print->error = 2;
			if (print->prec == 0 && w == 0)
				print->error = 9;
		}
	}
	return (i);
}

void	ft_fill_print(t_int *print, const char *format, va_list ap)
{
	int	i;

	i = print->index;
	if (format[i] != 'c' && format[i] != 's' && format[i] != 'p'
		&& format[i] != 'd' && format[i] != 'i' && format[i] != 'u'
		&& format[i] != 'x' && format[i] != 'X' && format[i] != '%')
	{
		i = ft_fill_zero_minus(&(*print), format, i);
		i = ft_fill_width(&(*print), format, i, ap);
		i = ft_fill_prec(&(*print), format, i, ap);
	}
	ft_conversion(ap, &(*print), i, format);
	print->len = 0;
	print->prec = 0;
	print->index = i;
	print->type = 0;
	print->error = 0;
	print->minus = 0;
	print->width = 0;
	print->zero = 0;
}
