/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 13:37:20 by mdirect           #+#    #+#             */
/*   Updated: 2020/01/05 16:37:31 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex_num		make_complex(double re, double im)
{
	t_complex_num number;

	number.im = im;
	number.re = re;
	return (number);
}

double				modul_complex(t_complex_num number)
{
	return (number.re * number.re + number.im *  number.im);
}
