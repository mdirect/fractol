/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 13:00:20 by mdirect           #+#    #+#             */
/*   Updated: 2020/01/22 15:03:41 by mdirect          ###   ########.fr       */
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
		f->max_i = ((f->max_i - 10) < 0) ? 0 : (f->max_i - 10);
	if (key == 69 || key == 24)
		f->max_i += 10;
	if (key >= 123 && key <= 126)
		key_move(key, f);
	if (key == 12)
		f->color -= 0.01;
	if (key == 13)
		f->color += 0.01;
	if (key == 49)
		f->press_space = !(f->press_space);
	if (key == 11)
		make_begin_params(f);
	if ((key > 82 && key < 90) || key == 91)
		change_formula(key, f);
	draw_cl(f);
	return (0);
}

void		change_formula(int key, t_fractol *f)
{
	if (key == 83)
		f->type = 1;
	if (key == 84)
		f->type = 2;
	if (key == 85)
		f->type = 3;
	if (key == 86)
		f->type = 4;
	if (key == 87)
		f->type = 5;
	if (key == 88)
		f->type = 6;
	if (key == 89)
		f->type = 7;
	if (key == 91)
		f->type = 8;
	make_begin_params(f);
}

void		make_begin_params(t_fractol *f)
{
	f->max_i = 200;
	f->x = -2.0;
	f->y = -2.0;
	f->color = 0.0;
	f->zoom = 250.0;
	f->press_space = 0;
	f->mouse.press_l = 0;
	f->j = make_complex(-0.4, 0.6);
}

void		key_move(int key, t_fractol *f)
{
	if (key == 125)
		f->y -= 0.04;
	if (key == 126)
		f->y += 0.04;
	if (key == 123)
		f->x += 0.04;
	if (key == 124)
		f->x -= 0.04;
}
