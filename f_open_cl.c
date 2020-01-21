/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_open_cl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 17:48:39 by mdirect           #+#    #+#             */
/*   Updated: 2020/01/21 23:29:54 by estel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

t_cl	start_cl(void)
{
	t_cl	cl;

	cl.ret = clGetPlatformIDs(1, &cl.platforms, &cl.num_platforms);
	cl.ret = clGetDeviceIDs(cl.platforms, CL_DEVICE_TYPE_DEFAULT, 1,
			&cl.device, &cl.num_devices);
	cl.context = clCreateContext(NULL, 1, &cl.device, NULL, NULL, &cl.ret);
	cl.command_queue = clCreateCommandQueue(cl.context, cl.device, 0, &cl.ret);
	return (cl);
}

void 	compile_cl(t_fractol *f)
{
	cl_program 	program = NULL;
	int 		fd;
	size_t 		source_size;
	char 		*source_str;

	fd = open("../open_cl.cl", O_RDONLY);
	if (!fd)
	{
		fprintf(stderr, "Failed to load kernel.\n");
		exit(1);
	}
	source_str = (char *)malloc(MAX_SOURCE_SIZE);
	source_size = read(fd, source_str, MAX_SOURCE_SIZE);
	close(fd);

	f->cl.kernel = NULL;
	program = clCreateProgramWithSource(f->cl.context, 1, (const char **)&source_str,
			(const size_t *)&source_size, &f->cl.ret);
	printf("ret=%d\n", f->cl.ret);
	f->cl.ret = clBuildProgram(program, 1, &f->cl.device, NULL, NULL, NULL);
	printf("ret=%d\n", f->cl.ret);
	if (f->cl.ret)
		write(1, "!Wrong RET!\n", 12);
	f->cl.kernel = clCreateKernel(program, "test", &f->cl.ret);
	make_buf_cl(f);
}

void 	make_buf_cl(t_fractol *f)
{
	f->cl.memobj = clCreateBuffer(f->cl.context, CL_MEM_READ_WRITE,
			(WIN_X * WIN_Y) * sizeof(cl_int), NULL, &f->cl.ret);
	f->cl.ret = clEnqueueWriteBuffer(f->cl.command_queue, f->cl.memobj, CL_TRUE, 0,
			(WIN_X * WIN_Y) * sizeof(cl_int), f->win.img_data, 0, NULL, NULL);
	printf("ret=%d\n", f->cl.ret);
	f->cl.ret = clSetKernelArg(f->cl.kernel, 0, sizeof(cl_mem), (void *)&f->cl.memobj);
	printf("ret=%d\n", f->cl.ret);
	bin_cl(f);
}

void 	cl_arg(t_fractol *f)
{
	f->cl.ret = clSetKernelArg(f->cl.kernel, 1, sizeof(f->x), (void *)&f->x);
	f->cl.ret = clSetKernelArg(f->cl.kernel, 2, sizeof(f->y), (void *)&f->y);
	f->cl.ret = clSetKernelArg(f->cl.kernel, 3, sizeof(f->zoom), (void *)&f->zoom);
	f->cl.ret = clSetKernelArg(f->cl.kernel, 4, sizeof(f->type), (void *)&f->type);
	f->cl.ret = clSetKernelArg(f->cl.kernel, 5, sizeof(f->j.re), (void *)&f->j.re);
	f->cl.ret = clSetKernelArg(f->cl.kernel, 6, sizeof(f->j.im), (void *)&f->j.im);
	f->cl.ret = clSetKernelArg(f->cl.kernel, 7, sizeof(f->max_i), (void *)&f->max_i);
	f->cl.ret = clSetKernelArg(f->cl.kernel, 8, sizeof(f->color), (void *)&f->color);
}
void 	bin_cl(t_fractol *f)
{
	size_t global_work_size[1] = { WIN_X * WIN_Y };

	cl_arg(f);
	f->cl.ret = clEnqueueNDRangeKernel(f->cl.command_queue, f->cl.kernel, 1, NULL,
			global_work_size, NULL, 0, NULL, NULL);
	f->cl.ret = clEnqueueReadBuffer(f->cl.command_queue, f->cl.memobj, CL_TRUE, 0,
			(WIN_X * WIN_Y) * sizeof(cl_int), f->win.img_data, 0, NULL, NULL);
	printf("ret=%d\n\n", f->cl.ret);
	mlx_put_image_to_window(f->win.mlx, f->win.window, f->win.img, 0, 0);
}
