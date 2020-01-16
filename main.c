/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 12:41:49 by mdirect           #+#    #+#             */
/*   Updated: 2020/01/16 15:30:19 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int argc, char **argv)
{
	t_fractol f;

	if (argc == 1)
		return (ft_usage());
	else if (argc == 2)
		f.type = ft_parce_fractol(argv[1]);
	else
		return (write(1, "many parametrs\n", 15));
	f.win.mlx = mlx_init();
	f.win.window = mlx_new_window(f.win.mlx, WIN_X, WIN_Y, "fract'ol");
	f.win.img = mlx_new_image(f.win.mlx, WIN_X, WIN_Y);
	f.max_i = 100;
	f.x = -2.0;
	f.y = -2.0;
	f.color = 0.0;
	f.j = make_complex(-0.4, 0.6);
	mlx_put_image_to_window(f.win.mlx, f.win.window, f.win.img, 0, 0);
	draw_fractol(&f);
	push_control(&f);
	mlx_loop(f.win.mlx);
	return (0);
}
