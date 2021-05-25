/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 19:12:40 by ebodart           #+#    #+#             */
/*   Updated: 2021/05/25 19:46:53 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef enum e_conv
{
	CHAR = 0,
	STRING = 1,
	POINTEUR = 2,
	INT = 3,
	UNINT = 4,
	HEXALOW = 5,
	HEXAUP = 6,
	PERCENT = 7
}	t_conv;

typedef struct s_int
{
	int	index;
	int	ret;
	int	len;
	int	minus;
	int	zero;
	int	width;
	int	prec;
	int	error;
	int	type;
}	t_int;

void	ft_fill_print(t_int *print, const char *format, va_list ap);
int		ft_fill_prec(t_int *print, const char *format, int i, va_list ap);
int		ft_fill_width(t_int *print, const char *format, int i, va_list ap);
int		ft_fill_zero_minus(t_int *print, const char *format, int i);

void	ft_write_minus(t_int *print);
void	ft_write_zero(t_int *print);
void	ft_write_width(t_int *print);

void	ft_conv_char(va_list ap, t_int *print);

void	ft_conv_percent(t_int *print);

char	*ft_unitoa(unsigned int n);
char	*ft_intchar(unsigned int n, int len_int, int signe);
int		ft_len_int(unsigned int n, int len_int);
char	*ft_itoa(int n);

char	*ft_int_in_hexa(unsigned long n, char *base, t_int *print);
char	*ft_intchar_base(unsigned long n, char *base, int len_int,
			unsigned long len_base);
int		ft_len_int_base(unsigned long n, int len_int,
			unsigned long len_base, t_int *print);

char	*ft_check_arg_str(va_list ap, t_int *print);
void	ft_putstr(char *str, t_int *print);
void	ft_conv_string(va_list ap, t_int *print);

char	*ft_check_arg_hexa(va_list ap, t_int *print);
void	ft_conv_hexa(va_list ap, t_int *print);

char	*ft_check_arg_int(va_list ap, t_int *print);
void	ft_putnbr(char *str, t_int *print);
void	ft_conv_integer(va_list ap, t_int *print);

char	*ft_check_arg_unint(va_list ap, t_int *print);
void	ft_conv_uninteger(va_list ap, t_int *print);

char	*ft_check_arg_ptr(va_list ap, t_int *print);
void	ft_conv_pointeur(va_list ap, t_int *print);

void	ft_init_struct(t_int *print);
void	ft_putchar(char c, t_int *print);
size_t	ft_strlen(const char *s);
void	ft_conversion(va_list ap, t_int *print, int i, const char *format);
int		ft_printf(const char *format, ...);

#endif