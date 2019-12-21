/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 12:43:06 by mdirect           #+#    #+#             */
/*   Updated: 2019/12/21 15:22:43 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FRACTOL_FRACTOL_H
# define FRACTOL_FRACTOL_H
# define SIZE_WIN_X 1600
# define SIZE_WIN_Y 1200

#include "minilibx_macos/mlx.h"
#include <unistd.h>
#include <stdlib.h>

typedef struct		s_complex_num
{
	double			im;
	double			re;
}					t_complex_num;

typedef struct 		s_param_window
{
	void			*window;
	void			*mlx;
	void			*img;
}					t_param_window;

void				draw_fractol(t_param_window win);
int					push_key(int key, void *param);
t_complex_num		make_complex(double im, double re);
double				modul_complex(t_complex_num number);

#endif