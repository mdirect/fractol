/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 12:43:06 by mdirect           #+#    #+#             */
/*   Updated: 2020/01/21 09:12:13 by estel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_FRACTOL_H
# define FRACTOL_FRACTOL_H
# define WIN_X 1001
# define WIN_Y 1001
# define MAX_SOURCE_SIZE 10000
# ifdef cl_khr_fp64
#  pragma OPENCL EXTENSION cl_khr_fp64 : enable
# elif defined(cl_amd_fp64)
#  pragma OPENCL EXTENSION cl_amd_fp64 : enable
# endif

# include <OpenCL/opencl.h>
# include "minilibx_macos/mlx.h"
# include <math.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct 		s_cl
{
	cl_int				ret;
	cl_context			context;
	cl_command_queue	command_queue;
	cl_platform_id		platforms;
	cl_uint				num_platforms;
	cl_device_id		device;
	cl_uint				num_devices;
	cl_kernel 			kernel;
	cl_mem 				memobj;
}					t_cl;

typedef struct		s_complex_num
{
	float			im;
	float			re;
}					t_complex_num;

typedef struct 		s_param_window
{
	void			*window;
	void			*mlx;
	void			*img;
	int				*img_data;
	int 			win_x;
}					t_param_window;

typedef struct		s_mouse
{
	int				press_l;
}					t_mouse;

typedef struct		s_fractol
{
	t_param_window	win;
	int 			type;
	float 			zoom;
	int				max_i;
	float 			x;
	float 			y;
	float 			color;
	t_complex_num	c;
	t_complex_num	j;
	t_mouse			mouse;
	t_cl			cl;
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
void				make_fractol(t_fractol *f);
t_cl				start_cl(void);
void 				compile_cl(t_fractol *f);
void 				make_buf_cl(t_fractol *f);
void 				bin_cl(t_fractol *f);

#endif
