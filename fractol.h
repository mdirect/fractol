/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 12:43:06 by mdirect           #+#    #+#             */
/*   Updated: 2020/01/08 17:07:57 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FRACTOL_FRACTOL_H
# define FRACTOL_FRACTOL_H
# define WIN_X 1001
# define WIN_Y 1001

#include "minilibx_macos/mlx.h"
#include <math.h>
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

typedef struct		s_fractol
{
	t_param_window	win;
	int 			type;
	int 			max_i;
	double 			x;
	double 			y;
	t_complex_num	c;
}					t_fractol;

void				draw_fractol(t_fractol *f);
int					push_key(int key, t_fractol *f);
t_complex_num		make_complex(double re, double im);
double				modul_complex(t_complex_num number);
int					ft_parce_fractol(char *s);
int					ft_usage(void);

#endif