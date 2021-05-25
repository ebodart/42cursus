/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 19:51:13 by ebodart           #+#    #+#             */
/*   Updated: 2021/05/25 19:25:42 by ebodart          ###   ########.fr       */
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

	printf("|Mon return_test = %d\n", ft_printf("%-9.1s", NULL));
	printf("|Vrai return_test = %d\n", printf("%-9.1s", NULL));
	printf("00000000000\n");
	printf("\n");
	printf("|Mon return_test = %d\n", ft_printf("%-3.1s", NULL));
	printf("|Vrai return_test = %d\n", printf("%-3.1s", NULL));
	printf("00000000000\n");
	printf("\n");
	printf("|Mon return_test = %d\n", ft_printf("%-3.8s", NULL));
	printf("|Vrai return_test = %d\n", printf("%-3.8s", NULL));
	printf("00000000000\n");
	printf("\n");
	printf("|Mon return_test = %d\n", ft_printf("%3.6s", NULL));
	printf("|Vrai return_test = %d\n", printf("%3.6s", NULL));
	printf("00000000000\n");
	printf("\n");
	printf("|Mon return_test = %d\n", ft_printf("%3.1s", NULL));
	printf("|Vrai return_test = %d\n", printf("%3.1s", NULL));
	printf("00000000000\n");
	printf("\n");
	printf("|Mon return_test = %d\n", ft_printf("%3.5s", NULL));
	printf("|Vrai return_test = %d\n", printf("%3.5s", NULL));
	printf("00000000000\n");
	printf("\n");
	printf("|Mon return_test = %d\n", ft_printf("%3.6s", NULL));
	printf("|Vrai return_test = %d\n", printf("%3.6s", NULL));
	printf("00000000000\n");
	printf("\n");

}
