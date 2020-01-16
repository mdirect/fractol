/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_julia.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 14:25:31 by mdirect           #+#    #+#             */
/*   Updated: 2020/01/16 15:46:04 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		julia(t_fractol *f)
{
	int				i;
	t_complex_num	z;

	i = 0;
	z = make_complex(f->c.re, f->c.im);
	while (modul_complex(z) <= 4 && i < f->max_i)
	{
		z = make_complex(z.re * z.re - z.im * z.im + f->j.re,
				2.0 * z.re * z.im + f->j.im);
		i++;
	}
	return (i);
}

int		mandelbrot_2(t_fractol *f)
{
	int				i;
	t_complex_num	z;

	i = 0;
	z = make_complex(f->c.re, f->c.im);
	while (modul_complex(z) <= 4 && i < f->max_i)
	{
		z = make_complex(z.re * z.re - z.im * z.im + f->c.re,
				2.0 * z.re * z.im + f->c.im);
		i++;
	}
	return (i);
}

int		mandelbrot_3(t_fractol *f)
{
	int				i;
	t_complex_num	z;

	i = 0;
	z = make_complex(f->c.re, f->c.im);
	while (modul_complex(z) <= 4 && i < f->max_i)
	{
		z = make_complex(z.re * z.re * z.re - 3 * z.re * z.im * z.im + f->c.re,
				3 * z.re * z.re * z.im - z.im * z.im * z.im + f->c.im);
		i++;
	}
	return (i);
}

int		mandelbrot_4(t_fractol *f)
{
	int				i;
	t_complex_num	z;

	i = 0;
	z = make_complex(f->c.re, f->c.im);
	while (modul_complex(z) <= 4 && i < f->max_i)
	{
		z = make_complex(z.re * z.re * z.re * z.re - 6 * z.re * z.re * z.im
				* z.im + z.im * z.im * z.im * z.im + f->c.re, 4 * z.re * z.re
				* z.re * z.im - 4 * z.re * z.im * z.im * z.im + f->c.im);
		i++;
	}
	return (i);
}

int		mandelbrot_5(t_fractol *f)
{
	int				i;
	t_complex_num	z;

	i = 0;
	z = make_complex(f->c.re, f->c.im);
	while (modul_complex(z) <= 4 && i < f->max_i)
	{
		z = make_complex(pow(z.re, 5) - 10 * pow(z.re, 3) * z.im * z.im + 5
				* z.re * pow(z.im, 4) + f->c.re, 5 * pow(z.re, 4) * z.im
				- 10 * z.re * z.re * pow(z.im, 3) + pow(z.im, 5) + f->c.im);
		i++;
	}
	return (i);
}
