/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 12:41:49 by mdirect           #+#    #+#             */
/*   Updated: 2020/01/18 20:13:47 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int argc, char **argv)
{
	t_fractol	f;
	t_cl 		cl;

	if (argc == 1)
		return (ft_usage());
	else if (argc == 2)
		f.type = ft_parce_fractol(argv[1]);
	else
		return (write(1, "many parametrs\n", 15));
	cl = start_cl();
	if (cl.ret)
		return (write(1, "Wrong RET!\n", 11));
	make_fractol(&f);
	compile_cl(&cl, &f);


	mlx_put_image_to_window(f.win.mlx, f.win.window, f.win.img, 0, 0);

//	draw_fractol(&f);
	push_control(&f);
	mlx_loop(f.win.mlx);
	return (0);
}
