/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 13:44:56 by mdirect           #+#    #+#             */
/*   Updated: 2020/01/16 16:18:38 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			make_color(int i, t_fractol *f)
{
	int		r;
	int		g;
	int		b;
	double	t;

	t = f->color + (double)i / (double)f->max_i;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((r << 16) | (g << 8) | b);
}

void		draw_fractol(t_fractol *f)
{
	int x;
	int y;

	y = 0;
	while (y < WIN_Y)
	{
		f->c.im = f->y + (double)y / f->zoom;
		x = 0;
		while (x < WIN_X)
		{
			f->c.re = f->x + (double)x / f->zoom;
			mlx_pixel_put(f->win.mlx, f->win.window, x, y,
					make_color(formula(f), f));
			x++;
		}
		y++;
	}
}