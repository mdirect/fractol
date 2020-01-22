/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 12:41:49 by mdirect           #+#    #+#             */
/*   Updated: 2020/01/22 19:11:00 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int argc, char **argv)
{
	t_fractol	f;

	if (argc == 1)
		return (ft_usage());
	else if (argc == 2)
	{
		if ((f.type = init_fractol(argv[1])) == 0)
			return (ft_usage());
	}
	else
		return (write(1, "many parametrs\n", 15));
	create_fractol(&f);
	compile_cl(&f);
	push_control(&f);
	mlx_loop(f.win.mlx);
	return (0);
}
