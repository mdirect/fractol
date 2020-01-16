/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 13:00:20 by mdirect           #+#    #+#             */
/*   Updated: 2020/01/16 20:58:28 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		push_control(t_fractol *f)
{
	mlx_hook(f->win.window, 2, 0, push_key, f);
	mlx_hook(f->win.window, 4, 0, push_mouse, f);
	mlx_hook(f->win.window, 5, 0, repush_mouse, f);
	mlx_hook(f->win.window, 6, 0, move_mouse, f);
}

int			push_key(int key, t_fractol *f)
{
	if (key == 53)
		exit(0);
	if (key == 78 || key == 27)
		f->max_i -= 10;
	if (key == 69 || key == 24)
		f->max_i += 10;
	if (key == 125)
		f->y -= 0.04;
	if (key == 126)
		f->y += 0.04;
	if (key == 123)
		f->x += 0.04;
	if (key == 124)
		f->x -= 0.04;
	if (key == 12)
		f->color -= 0.01;
	if (key == 13)
		f->color += 0.01;
	if ((key > 82 && key < 90) || key == 91)
		change_formula(key, f);
	mlx_clear_window(f->win.mlx, f->win.window);
	draw_fractol(f);
	return (0);
}

int 		move_mouse(int x, int y, void *param)
{
	t_fractol *f;

	f = (t_fractol *)param;
	if (f->mouse.press_l && f->type == 1)
	{
		f->j.re = f->x + (double)x / 250;
		f->j.im = f->y + (double)y / 250;
		mlx_clear_window(f->win.mlx, f->win.window);
		draw_fractol(f);
	}
	return (0);
}

int			push_mouse(int key, int x, int y, void *param)
{
	t_fractol *f;

	(void)x;
	(void)y;
	f = (t_fractol *)param;
	if (key == 4 || key == 5)
		zoom(key, (double)x, (double)y, f);
	if (key == 1)
		f->mouse.press_l = 1;
	return (0);
}

int			repush_mouse(int key, int x, int y, void *param)
{
	t_fractol *f;

	(void)x;
	(void)y;
	(void)key;
	f = (t_fractol *)param;
	f->mouse.press_l = 0;
	return (0);
}

void		zoom(int key, double x, double y, t_fractol *f)
{
	int pre_z;

	pre_z = f->zoom;
//	x = x / f->zoom;
//	y = y / f->zoom;
	if (key == 4)
	{
		f->zoom += 50;
		f->y =  (f->y + y / pre_z) * pre_z / f->zoom;
		f->x =  (f->x + x / pre_z) * pre_z / f->zoom;
	}
	if (key == 5)
	{
		f->zoom -= 50;
		f->y =  (f->y + y / pre_z) * pre_z / f->zoom;
		f->x =  (f->x + x / pre_z) * pre_z / f->zoom;
	}
	mlx_clear_window(f->win.mlx, f->win.window);
	draw_fractol(f);
}
