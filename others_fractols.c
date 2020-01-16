/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others_fractols.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 15:16:32 by mdirect           #+#    #+#             */
/*   Updated: 2020/01/16 15:27:44 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		bird(t_fractol *f)
{
	int				i;
	t_complex_num	z;

	i = 0;
	z = make_complex(f->c.re, f->c.im);
	while (modul_complex(z) <= 4 && i < f->max_i)
	{
		z = make_complex(fabs(z.re * z.re - z.im * z.im) + f->c.re,
				2.0 * z.re * z.im + f->c.im);
		i++;
	}
	return (i);
}

int		burning_ship(t_fractol *f)
{
	int				i;
	t_complex_num	z;

	i = 0;
	z = make_complex(f->c.re, f->c.im);
	while (modul_complex(z) <= 4 && i < f->max_i)
	{
		z = make_complex(z.re * z.re - z.im * z.im + f->c.re,
				2.0 * fabs(z.re * z.im) + f->c.im);
		i++;
	}
	return (i);
}

int		mandelbar(t_fractol *f)
{
	int				i;
	t_complex_num	z;

	i = 0;
	z = make_complex(f->c.re, f->c.im);
	while (modul_complex(z) <= 4 && i < f->max_i)
	{
		z = make_complex(z.re * z.re - z.im * z.im + f->c.re,
				-2.0 * z.re * z.im + f->c.im);
		i++;
	}
	return (i);
}
