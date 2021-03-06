/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 18:40:27 by ebodart           #+#    #+#             */
/*   Updated: 2021/05/26 21:05:03 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_write_minus(t_int *print)
{
	int	w;

	w = print->len;
	if (print->len < print->prec && print->prec > 0
		&& (print->type >= 3 || print->type == -3))
		w = print->prec;
	else if (print->len >= print->prec && print->prec > 0 && print->type == 1)
		w = print->prec;
	else if ((print->error == 2 || print->error == 9) && print->type == 1)
		w = 0;
	w = print->width - w;
	while (w > 0)
	{
		ft_putchar(' ', &(*print));
		w--;
	}
	print->width = 0;
}

void	ft_write_zero(t_int *print)
{
	int	w;

	w = print->len;
	if (print->type == -3)
		ft_putchar('-', &(*print));
	if (print->len >= print->prec && print->prec > 0)
		w = print->prec;
	w = print->width - w;
	while (w > 0)
	{
		ft_putchar('0', &(*print));
		w--;
	}
	print->width = 0;
}

void	ft_change_width(t_int *print)
{
	print->width *= -1;
	print->minus = 1;
}

void	ft_write_width(t_int *print)
{
	int	w;

	w = print->len;
	if (print->len < print->prec && print->prec > 0
		&& (print->type >= 3 || print->type == -3))
		w = print->prec;
	else if (print->len >= print->prec && print->prec > 0 && print->type == 1)
		w = print->prec;
	else if ((print->error == 9 || print->error == 2) && print->type == 1)
		w = 0;
	w = print->width - w;
	if (print->prec <= 0 && print->width < print->len && print->type >= 2)
		w = 0;
	while (w > 0)
	{
		ft_putchar(' ', &(*print));
		w--;
	}
	print->width = 0;
}
