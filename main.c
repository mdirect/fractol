/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 12:41:49 by mdirect           #+#    #+#             */
/*   Updated: 2019/12/21 14:44:23 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int 	main(void)
{
	t_param_window win;

	win.mlx = mlx_init();
	win.window = mlx_new_window(win.mlx, SIZE_WIN_X, SIZE_WIN_Y, "fract'ol");
	win.img = mlx_new_image(win.mlx, SIZE_WIN_X, SIZE_WIN_Y);
	mlx_put_image_to_window(win.mlx, win.window, win.img, 0, 0);
	mlx_string_put(win.mlx, win.window, 20, 10, 0xffffff, "Fract'ol");
	draw_fractol(win);
	mlx_hook(win.window, 2, 0, push_key, win.mlx);
	mlx_loop(win.mlx);
	return (0);
}
