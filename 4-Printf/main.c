/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 19:51:13 by ebodart           #+#    #+#             */
/*   Updated: 2021/05/23 18:07:49 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char	c;
	char *str;
	static char *s_hidden = "hi low\0don't print me lol\0";
	int len;

	c = 'K';
	str = "hello";

	printf("|Mon return_test = %d\n", ft_printf("%.0i", 0));
	printf("|Vrai return_test = %d\n", printf("%.0i", 0));
	printf("00000000000\n");
	printf("\n");
	printf("|Mon return_test = %d\n", ft_printf("%010.5i", -846));
	printf("|Vrai return_test = %d\n", printf("%010.5i", -846));
	printf("00000000000\n");
	printf("\n");
}
