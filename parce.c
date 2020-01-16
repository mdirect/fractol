/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 14:35:58 by mdirect           #+#    #+#             */
/*   Updated: 2020/01/08 14:35:58 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_parce_fractol(char *s)
{
	if (*s == 'j' && !(*(s + 1)))
		return (1);
	if (*s == 'm' && *(s + 1) == '2' && !(*(s + 2)))
		return (2);
	if (*s == 'm' && *(s + 1) == '3' && !(*(s + 2)))
		return (3);
	if (*s == 'm' && *(s + 1) == '4' && !(*(s + 2)))
		return (4);
	if (*s == 'm' && *(s + 1) == '5' && !(*(s + 2)))
		return (5);
	if (*s == 'b' && !(*(s + 1)))
		return (6);
	if (*s == 'b' && *(s + 1) == 's' && !(*(s + 2)))
		return (7);
	if (*s == 'm' && *(s + 1) == 'b' && !(*(s + 2)))
		return (8);
	return (0);
}

int		ft_usage(void)
{
	write(1, "usage: ./fractol input_fractol\n", 31);
	write(1, "j  - Julia\n", 11);
	write(1, "m2 - Mandelbrot\n", 16);
	write(1, "m3 - Mandelbrot^3\n", 18);
	write(1, "m4 - Mandelbrot^4\n", 18);
	write(1, "m5 - Mandelbrot^5\n", 18);
	write(1, "b  - Bird\n", 10);
	write(1, "bs - Burning Ship\n", 18);
	write(1, "mb - Mandelbar\n", 16);
	return (0);
}
