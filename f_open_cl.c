/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_open_cl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 17:48:39 by mdirect           #+#    #+#             */
/*   Updated: 2020/01/18 20:10:32 by mdirect          ###   ########.fr       */
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

void 	compile_cl(t_cl *cl, t_fractol *f)
{
	cl_program 	program = NULL;
	cl_kernel 	kernel = NULL;
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

	program = clCreateProgramWithSource(cl->context, 1, (const char **)&source_str,
			(const size_t *)&source_size, &cl->ret);
	cl->ret = clBuildProgram(program, 1, &cl->device, NULL, NULL, NULL);
	if (cl->ret)
		write(1, "!Wrong RET!\n", 12);
	kernel = clCreateKernel(program, "test", &cl->ret);
	make_buf_cl(cl, &kernel, f);
}

void 	make_buf_cl(t_cl *cl, cl_kernel *kernel, t_fractol *f)
{
	cl_mem	memobj = NULL;

	memobj = clCreateBuffer(cl->context, CL_MEM_READ_WRITE,
			(WIN_X * WIN_Y) * sizeof(cl_int), NULL, &cl->ret);
	cl->ret = clEnqueueWriteBuffer(cl->command_queue, memobj, CL_TRUE, 0,
			(WIN_X * WIN_Y) * sizeof(cl_int), f->win.img_data, 0, NULL, NULL);
	cl->ret = clSetKernelArg(*kernel, 0, sizeof(cl_mem), (void *)&memobj);
	bin_cl(cl, kernel, &memobj, f);
}

void 	bin_cl(t_cl *cl, cl_kernel *kernel, cl_mem *memobj, t_fractol *f)
{
	size_t global_work_size[1] = { WIN_X * WIN_Y };

	cl->ret = clEnqueueNDRangeKernel(cl->command_queue, *kernel, 1, NULL,
			global_work_size, NULL, 0, NULL, NULL);
	printf("ret=%d\n", cl->ret);
	cl->ret = clEnqueueReadBuffer(cl->command_queue, *memobj, CL_TRUE, 0,
			(WIN_X * WIN_Y) * sizeof(cl_int), f->win.img_data, 0, NULL, NULL);
	printf("ret=%d\n", cl->ret);
	printf("%d\n", f->win.img_data[0]);
}
