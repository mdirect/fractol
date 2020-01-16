/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formula.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 16:23:20 by mdirect           #+#    #+#             */
/*   Updated: 2020/01/16 16:31:12 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		formula(t_fractol *f)
{
	if (f->type == 1)
		return (julia(f));
	if (f->type == 2)
		return (mandelbrot_2(f));
	if (f->type == 3)
		return (mandelbrot_3(f));
	if (f->type == 4)
		return (mandelbrot_4(f));
	if (f->type == 5)
		return (mandelbrot_5(f));
	if (f->type == 6)
		return (bird(f));
	if (f->type == 7)
		return (burning_ship(f));
	if (f->type == 8)
		return (mandelbar(f));
	return (0);
}

void	change_formula(int key, t_fractol *f)
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
}
