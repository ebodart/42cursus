/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 19:51:13 by ebodart           #+#    #+#             */
/*   Updated: 2021/05/26 19:29:53 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char *str;
	static char *s_hidden = "hi low\0don't print me lol\0";
	int len;
	int		a = 12;
	int		b = 14;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";

	printf("--- Return : %d\n", ft_printf("%-3.s", s_hidden));
	printf("--- Return : %d\n", printf("%-3.s", s_hidden));
	printf("00000000000\n");
	printf("\n");
	printf("--- Return : %d\n", ft_printf("%-8.s", s_hidden));
	printf("--- Return : %d\n", printf("%-8.s", s_hidden));
	printf("00000000000\n");
	printf("\n");
	printf("--- Return : %d\n", ft_printf("%-3.s", NULL));
	printf("--- Return : %d\n", printf("%-3.s", NULL));
	printf("00000000000\n");
	printf("\n");
	printf("--- Return : %d\n", ft_printf("%-8.s", NULL));
	printf("--- Return : %d\n", printf("%-8.s", NULL));
	printf("00000000000\n");
	printf("\n");
}