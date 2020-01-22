/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 13:37:20 by mdirect           #+#    #+#             */
/*   Updated: 2020/01/22 14:35:16 by mdirect          ###   ########.fr       */
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

void				ret_error(int code)
{
	if (code)
	{
		write(1, "error while set openCL values: ", 31);
		ft_putnbr(code);
		write(1, "\n", 1);
		exit(code);
	}
}
