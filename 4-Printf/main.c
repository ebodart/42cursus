/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 19:51:13 by ebodart           #+#    #+#             */
/*   Updated: 2021/05/24 20:09:56 by ebodart          ###   ########.fr       */
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

	printf("|Mon return_test = %d\n", ft_printf("%2x", 94827));
	printf("|Vrai return_test = %d\n", printf("%2x", 94827));
	printf("00000000000\n");
	printf("\n");
}
