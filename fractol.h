/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 12:43:06 by mdirect           #+#    #+#             */
/*   Updated: 2020/01/16 19:14:38 by mdirect          ###   ########.fr       */
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

typedef struct		s_mouse
{
	int				press_l;
}					t_mouse;

typedef struct		s_fractol
{
	t_param_window	win;
	int 			type;
	int 			zoom;
	int 			max_i;
	double 			x;
	double 			y;
	double 			color;
	t_complex_num	c;
	t_complex_num	j;
	t_mouse			mouse;
}					t_fractol;

void				draw_fractol(t_fractol *f);
void				push_control(t_fractol *f);
int					push_key(int key, t_fractol *f);
int					push_mouse(int key, int x, int y, void *param);
int					repush_mouse(int key, int x, int y, void *param);
int 				move_mouse(int x, int y, void *param);
void				zoom(int key, double x, double y, t_fractol *f);
t_complex_num		make_complex(double re, double im);
double				modul_complex(t_complex_num number);
int					ft_parce_fractol(char *s);
int					ft_usage(void);
int					formula(t_fractol *f);
void				change_formula(int key, t_fractol *f);
int					julia(t_fractol *f);
int					mandelbrot_2(t_fractol *f);
int					mandelbrot_3(t_fractol *f);
int					mandelbrot_4(t_fractol *f);
int					mandelbrot_5(t_fractol *f);
int					bird(t_fractol *f);
int					burning_ship(t_fractol *f);
int					mandelbar(t_fractol *f);


#endif