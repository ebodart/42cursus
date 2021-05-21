/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 18:37:43 by ebodart           #+#    #+#             */
/*   Updated: 2021/05/21 10:45:12 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_check_arg(va_list ap)
{
	char	*str;

	str = va_arg(ap, char *);
	if (!str || str == 0)
	{
		str = "null";
	}
	return (str);
}

void	ft_putstr(char *str, t_int *print)
{
	int	i;
	int	l;

	i = 0;
	if (print->prec > 0 && print->len > print->prec)
		l = print->prec;
	else if (print->prec < 0)
		l = 0;
	else
		l = print->len;
	while (l > 0)
	{
		ft_putchar(str[i], &(*print));
		l--;
		i++;
	}
}

void	ft_conv_string(va_list ap, t_int *print)
{
	char	*str;

	str = ft_check_arg(ap);
	if (print->error != 0)
		return ;
	print->len = ft_strlen(str);
	if (print->minus > 0)
	{
		ft_putstr(str, &(*print));
		ft_write_minus(&(*print));
	}
	else if (print->zero > 0)
	{
		ft_write_zero(&(*print));
		ft_putstr(str, &(*print));
	}
	else if (print->width > 0)
	{
		ft_write_width(&(*print));
		ft_putstr(str, &(*print));
	}
	else
		ft_putstr(str, &(*print));
}
