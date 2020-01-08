/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 13:44:56 by mdirect           #+#    #+#             */
/*   Updated: 2020/01/08 17:11:24 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		make_color(int i, t_fractol *f)
{
	int		r;
	int		g;
	int		b;
	double	t;

	t = (double)i/ (double)f->max_i;
	r = (int)(9 * (1 - t) * (t * t * t) * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((r << 16) | (g << 8) | b);
}

void		draw_fractol(t_fractol *f)
{
	t_complex_num z;
	int x;
	int y;
	int i;

	y = 0;
	while (y < WIN_Y)
	{
		f->c.im = f->y + (double)y / 250;
		x = 0;
		while (x < WIN_X)
		{
			f->c.re = f->x + (double)x / 250;
			z = make_complex(f->c.re, f->c.im);
			i = 0;
			while (modul_complex(z) <= 4 && i < f->max_i)
			{
//				z = make_complex(z.re * z.re * z.re * z.re - 6 * z.re * z.re * z.im * z.im + z.im * z.im * z.im * z.im + f->c.re,
//						4 * z.re * z.re * z.re * z.im - 4 * z.re * z.im * z.im * z.im + f->c.im);
//				z = make_complex(z.re * z.re * z.re - 3 * z.re * z.im * z.im + f->c.re,
//						3 * z.re * z.re * z.im - z.im * z.im * z.im + f->c.im);
				z = make_complex(z.re * z.re - z.im * z.im + f->c.re,
						2.0 * z.re * z.im + f->c.im);
				i++;
			}
			mlx_pixel_put(f->win.mlx, f->win.window, x, y, make_color(i, f));
			x++;
		}
		y++;
	}
}
