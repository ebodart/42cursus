/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 19:51:13 by ebodart           #+#    #+#             */
/*   Updated: 2021/05/21 10:41:50 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char	c;
	char *str;
	static char *s_hidden = "hi low\0don't print me lol\0";

	c = 'K';
	str = "hello";

	
	printf("|Mon return_test = %d\n", ft_printf("%-3.s", s_hidden));
	printf("|Vrai return_test = %d\n", printf("%-3.s", s_hidden));
	printf("\n");
	printf("|Mon return_test = %d\n", ft_printf("%-8.s", s_hidden));
	printf("|Vrai return_test = %d\n", printf("%-8.s", s_hidden));
	printf("\n");
	printf("|Mon return_test = %d\n", ft_printf("%.*s", -3, 0));
	printf("|Vrai return_test = %d\n", printf("%.*s", -3, 0));
	printf("\n");
	printf("|Mon return_test = %d\n", ft_printf("%.*s", -1, 0));
	printf("|Vrai return_test = %d\n", printf("%.*s", -1, 0));
	printf("\n");
}
