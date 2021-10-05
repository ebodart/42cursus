/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 16:51:08 by ebodart           #+#    #+#             */
/*   Updated: 2021/10/05 14:48:13 by ebodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int main(int argc, char **argv)
{
	
	if (argc == 2 && ((ft_strcmp(argv[1], "Julia") == 0)
		|| (ft_strcmp(argv[1], "Mandelbrot") == 0)))
		printf("Cool");
	else
	{
		printf("Invalid argument\n");
		printf("Usage: ./fractol Julia OR ./fractol Mandelbrot\n");
	}
	return (0);
}