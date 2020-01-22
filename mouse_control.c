/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 13:04:01 by mdirect           #+#    #+#             */
/*   Updated: 2020/01/22 14:56:59 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			move_mouse(int x, int y, void *param)
{
	t_fractol *f;

	f = (t_fractol *)param;
	f->mouse.x_pred = f->mouse.x;
	f->mouse.y_pred = f->mouse.y;
	f->mouse.x = x;
	f->mouse.y = y;
	if (f->press_space == 0 && f->type == 1)
	{
		f->j.re = f->x + (double)x / f->zoom;
		f->j.im = f->y + (double)y / f->zoom;
		draw_cl(f);
	}
	if (f->mouse.press_l == 1)
	{
		f->x -= (x - f->mouse.x_pred) / f->zoom;
		f->y -= (y - f->mouse.y_pred) / f->zoom;
		draw_cl(f);
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
	if (key == 2)
		open_help(f);
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
	if (key == 2)
		draw_cl(f);
	return (0);
}

void		zoom(int key, double x, double y, t_fractol *f)
{
	double pre_z;

	pre_z = f->zoom;
	if (key == 4)
		f->zoom *= 1.1;
	if (key == 5)
		f->zoom /= 1.1;
	f->x = f->x + (x / pre_z + f->x) - (x / f->zoom + f->x);
	f->y = f->y + (y / pre_z + f->y) - (y / f->zoom + f->y);
	draw_cl(f);
}

void		open_help(t_fractol *f)
{
	mlx_clear_window(f->win.mlx, f->win.window);
	mlx_string_put(f->win.mlx, f->win.window, 100, 40, 0xffffff,
			"          MOVE: ARROW");
	mlx_string_put(f->win.mlx, f->win.window, 100, 60, 0xffffff,
			"                LEFT MOUSE BUTTON");
	mlx_string_put(f->win.mlx, f->win.window, 100, 80, 0xffffff,
			"          ZOOM: SCROLL");
	mlx_string_put(f->win.mlx, f->win.window, 100, 100, 0xffffff,
			"         COLOR: Q/W");
	mlx_string_put(f->win.mlx, f->win.window, 100, 120, 0xffffff,
			"     ITERATION: -/+");
	mlx_string_put(f->win.mlx, f->win.window, 100, 140, 0xffffff,
			"OTHER FRACTOLS: 1-9");
	mlx_string_put(f->win.mlx, f->win.window, 100, 160, 0xffffff,
			" BACK TO BEGIN: B");
	mlx_string_put(f->win.mlx, f->win.window, 100, 180, 0xffffff,
			"          HELP: RIGHT MOUSE BUTTON");
}
