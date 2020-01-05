/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 13:44:56 by mdirect           #+#    #+#             */
/*   Updated: 2020/01/05 19:24:22 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		draw_fractol(t_param_window win)
{
	t_complex_num min;
	t_complex_num max;
	t_complex_num delta;
	t_complex_num c, z;
	int x, y, i, max_i;
	double t;
	int r, g, b;

	min = make_complex(-2.0, -2.0);
	max = make_complex(2.0, 2.0);
	delta = make_complex((max.re - min.re) / (SIZE_WIN_X - 1),
			(max.im - min.im) / (SIZE_WIN_Y - 1));

	max_i = 100;
	y = 0;
	while (y < SIZE_WIN_Y)
	{
		c.im = min.im + y * delta.im;
		x = 0;
		while (x < SIZE_WIN_X)
		{
			c.re = min.re + x * delta.re;
			z = make_complex(c.re, c.im);
			i = 0;
			while (modul_complex(z) <= 4 && i < max_i)
			{
//				z = make_complex(z.re * z.re * z.re * z.re - 6 * z.re * z.re * z.im * z.im + z.im * z.im * z.im * z.im + c.re,
//						4 * z.re * z.re * z.re * z.im - 4 * z.re * z.im * z.im * z.im + c.im);
//				z = make_complex(z.re * z.re * z.re - 3 * z.re * z.im * z.im + c.re,
//						3 * z.re * z.re * z.im - z.im * z.im * z.im + c.im);
				z = make_complex(z.re * z.re - z.im * z.im + c.re,
						2.0 * z.re * z.im + c.im);
				i++;
			}
			t = (double)i/ (double)max_i;
			r = (int)(9 * (1 - t) * (t * t * t) * 255);
			g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
			b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
			mlx_pixel_put(win.mlx, win.window, x, y, (r<<8)|(g<<4)|b);
			x++;
		}
		y++;
	}
}
