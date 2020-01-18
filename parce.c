/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 14:35:58 by mdirect           #+#    #+#             */
/*   Updated: 2020/01/18 20:18:33 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			ft_parce_fractol(char *s)
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

int			ft_usage(void)
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

void	make_fractol(t_fractol *f)
{
	int 		bpp;
	int 		endian;

	f->win.mlx = mlx_init();
	f->win.window = mlx_new_window(f->win.mlx, WIN_X, WIN_Y, "fract'ol");
	f->win.img = mlx_new_image(f->win.mlx, WIN_X, WIN_Y);
	f->win.win_x = WIN_X;
	bpp = 32;
	endian = 0;
	f->win.img_data = (int *)mlx_get_data_addr(f->win.img, &bpp, &(f->win.win_x), &endian);
	f->max_i = 100;
	f->x = -2.0;
	f->y = -2.0;
	f->color = 0.0;
	f->zoom = 250.0;
	f->j = make_complex(-0.4, 0.6);
	mlx_put_image_to_window(f->win.mlx, f->win.window, f->win.img, 0, 0);
}
