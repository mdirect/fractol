/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 13:00:20 by mdirect           #+#    #+#             */
/*   Updated: 2020/01/08 17:00:01 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	mlx_clear_window(f->win.mlx, f->win.window);
	draw_fractol(f);
	return (0);
}
